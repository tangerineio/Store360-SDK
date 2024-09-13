/*
 *	@file TGRBeaconManager.h
 *	@framework Tangerine
 *
 *	@copyright 2014 Tangerine, Inc. All rights reserved.
 */
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class TGRBeacon, TGRBeaconManager;

typedef void (^TGRBeaconManangerDidRangeBeaconsBlockType)(TGRBeaconManager *manager,NSArray *targetTGRBeacons,NSArray *allRangerCLBeacons,NSString * timestampDevice);
typedef void (^TGRBeaconManangerDidExitBlockType)(TGRBeaconManager *manager,NSArray *beacons,NSString * timestampDevice);
typedef void (^TGRBeaconManangerFindBeaconsBlockType)(TGRBeaconManager *manager, NSArray *beacons, TGRBeacon *newBeacon, NSString *tsBeaconDetection);
typedef void (^TGRBeaconManangerUpdateSuccessBlockType)(TGRBeaconManager *manager, TGRBeacon *beacon);
typedef void (^TGRBeaconManangerUpdateFailedBlockType)(TGRBeaconManager *manager, TGRBeacon *beacon, NSError *error);
typedef void (^TGRBeaconManangerConnectSuccessBlockType)(TGRBeaconManager *manager, TGRBeacon *beacon);
typedef void (^TGRBeaconManangerConnectFailedBlockType)(TGRBeaconManager *manager, TGRBeacon *beacon, NSError *error);
//GeoFence parameters
typedef  void (^sigLoactionUpdateCallBack)(CLLocationCoordinate2D sigLoactionUpdateCallBack);;
typedef void (^geoFenceActionListCallBack)(NSDictionary *geoFenceActionListCallBack);




/*!
 *  Beaconを管理するクラスです。
 *
 *  ### BeaconManagerの役割
 *  - BeaconManagerはBeaconの情報を取得しTangerineCloudに同期します。
 *  - BeaconManagerはBeaconの情報を更新します。
 *
 */
@interface TGRBeaconManager : NSObject

@property (nonatomic) BOOL isOnlyFireEventClosest;

@property (nonatomic, strong) CLBeaconRegion *beaconRegion;
@property (nonatomic, strong) NSArray *beaconRegions;
@property (nonatomic, assign) BOOL monitoring;
@property (nonatomic, strong) NSString *beaconsUUID;

/*!
 * CLLocationManagerで発生するエラーを上位アプリ層でハンドリングするためのDelegate
 * CLLocationManagerDelegateの以下のエラー処理メソッドを呼び出されます。
 * エラーハンドリングしたいメソッドのみ任意で実装して下さい。
 * 
 * - (void)locationManager:(CLLocationManager *)manager
 *    monitoringDidFailForRegion:(CLRegion *)region
 *    withError:(NSError *)error
 *
 * - (void)locationManager:(CLLocationManager *)manager
 *    didFailWithError:(NSError *)error
 * 
 * - (void)locationManager:(CLLocationManager *)manager
 *   rangingBeaconsDidFailForRegion:(CLBeaconRegion *)region
 *   withError:(NSError *)error;
 */
@property (nonatomic, assign) id<CLLocationManagerDelegate> locationManagerErrorDelegate;


@property (nonatomic, assign) id delegate;

/*!
 * BeaconManagerのインスタンスを取得します。
 */
+ (instancetype)sharedInstance;

+ (BOOL) canDeviceSupportAppBackgroundRefresh;
+ (BOOL) isBluetoothActive;

/*!
 * LocationServiceが利用可能かチェックします。
 * 利用できない場合はAlertを表示します。
 */
+ (BOOL) isLocationServiceAvailable:(BOOL)showAlert;

/*!
 * 常にLocationServiceを利用する許可をリクエストします.
 * iOS8の新しいLocationService権限モデルに従うため、startMonitoringForRegion:didEnter:didExit: を実行する前に呼び出す必要があります。
 * この権限をリクエストする場合、必ずInfo.plistに「NSLocationAlwaysUsageDescription」を定義し、適切な説明文を記載して下さい。
 */
- (void) requestAlwaysAuthorization;

/*!
 * アプリがForegroundの間のみ、LocationServiceを利用する許可をリクエストします.
 * iOS8の新しいLocationService権限モデルに従うため、startMonitoringForRegion:didEnter:didExit: を実行する前に呼び出す必要があります。
 * この権限をリクエストする場合、必ずInfo.plistに「NSLocationWhenInUseUsageDescription」を定義し、適切な説明文を記載して下さい。
 */
- (void) requestWhenInUseAuthorization;

/*!
 *  BeaconRegionで指定されたUUIDのBeaconを検知しEnter/Exitイベントを監視します。
 *
 *  @param region UUIDで指定されたBeaconRegion
 *  @param didEnter BeaconRegionに入ったタイミングで呼び出されるBlock
 *  @param didExit BeaconRegionから出たタイミングで呼び出されるBlock
 */
- (void) startMonitoringForRegion:(CLBeaconRegion *)region
                         didEnter:(TGRBeaconManangerDidRangeBeaconsBlockType)didEnterBlock
                          didExit:(TGRBeaconManangerDidExitBlockType)didExitBlock;

/*!
 *  複数指定されたUUIDのBeaconを検知しEnter/Exitイベントを監視します。
 *
 *  @param regions UUIDの配列
 *  @param didEnter BeaconRegionに入ったタイミングで呼び出されるBlock
 *  @param didExit BeaconRegionから出たタイミングで呼び出されるBlock
 */
- (void) startMonitoringForRegions:(NSArray *)regions
                         didRangeBeacons:(TGRBeaconManangerDidRangeBeaconsBlockType)didEnterBlock
                          didExit:(TGRBeaconManangerDidExitBlockType)didExitBlock;



- (void) startMonitoringForGeoRegions:(NSArray *)regions didRangeBeacons:(TGRBeaconManangerDidRangeBeaconsBlockType)didEnterBlock didExit:(TGRBeaconManangerDidExitBlockType)didExitBlock;
/*!
 *  Beaconの監視を中止します。
 */
- (void) stopMonitoring;
- (void) clearFlxBeacons;

/*!
 * 周囲にある管理対象beaconを探索し、TGRBeaconのリストを返します。
 * @param beaconsBlock リスト取得時の処理Blockです。
 * @return スキャンを正常に開始できたかどうかを返します。YESの場合は正常に開始したことを意味します。
 */
- (BOOL) scanForBeacons:(TGRBeaconManangerFindBeaconsBlockType)beaconsBlock;

/*!
 * Beaconのスキャンを中止します。
 */
- (void) stopScan;

/*!
 * iBeaconデバイスの設定を保存します。
 * @param uuid ProximityUUIDの値
 * @param beacon 更新したいBeaconインスタンス
 * @param successBlock 更新処理に成功した場合のblock
 * @param failedBlock 更新処理に失敗した場合のblock
 */
- (void) saveBeacon:(TGRBeacon *)beacon
          onSuccess:(TGRBeaconManangerUpdateSuccessBlockType)successBlock
           onFailed:(TGRBeaconManangerUpdateFailedBlockType)failedBlock;

- (void) connectBeacon:(TGRBeacon *)beacon
             onSuccess:(TGRBeaconManangerConnectSuccessBlockType)successBlock
              onFailed:(TGRBeaconManangerConnectFailedBlockType)failedBlock;
- (void) disconnectBeacon:(TGRBeacon *)beacon;

/*!
 * DFUモードに入るように設定します.
 * @param beacon DFUしたいBeaconインスタンス
 * @param successBlock 処理に成功した場合のblock
 * @param failedBlock 処理に失敗した場合のblock
 */
- (void) enterDFUModeForBeacon:(TGRBeacon *)beacon
                     onSuccess:(TGRBeaconManangerUpdateSuccessBlockType)successBlock
                      onFailed:(TGRBeaconManangerUpdateFailedBlockType)failedBlock;

/*!
 * BeaconのLEDを点滅します.
 * @param beacon DFUしたいBeaconインスタンス
 * @param successBlock 処理に成功した場合のblock
 * @param failedBlock 処理に失敗した場合のblock
 */
- (void) blinkLightWithBeacon:(TGRBeacon *)beacon
                    onSuccess:(TGRBeaconManangerUpdateSuccessBlockType)successBlock
                     onFailed:(TGRBeaconManangerUpdateFailedBlockType)failedBlock;
-(BOOL)isPreciseLocationAvailable;
-(NSString*)currLocationStatus;

//GeoFence Handlers
-(void)startSignificantLocationMonitoring:(sigLoactionUpdateCallBack)sigLoactionUpdateCallBack actionListCallBack: (geoFenceActionListCallBack)geoFenceActionListCallBack;
-(void)stopSignificantLocationMonitoring;
-(void)startGeoFenceMonitoring:(NSMutableArray*)geoFenceListItems;

@end
