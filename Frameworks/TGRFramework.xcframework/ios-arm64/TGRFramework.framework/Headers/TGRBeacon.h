/*
 *	@file TGRBeacon
 *	@framework Tangerine
 *
 *	@copyright 2014 Tangerine, Inc. All rights reserved.
 */
#import <CoreBluetooth/CoreBluetooth.h>
#import <CoreLocation/CoreLocation.h>

/*!
 * TGRProximity
 */
typedef NS_ENUM(NSInteger, TGRProximity) {
	TGRProximityUnknown = CLProximityUnknown,
	TGRProximityImmediate = CLProximityImmediate,
	TGRProximityNear = CLProximityNear,
	TGRProximityFar = CLProximityFar
};

/*!
 * TGRBeaconStatus
 */
typedef NS_ENUM(NSInteger, TGRBeaconStatus) {
	TGRBeaconStatusNotProvisioned, // 未登録
	TGRBeaconStatusProvisioned, // 登録済み
	TGRBeaconStatusInitialized, // 初期設定済み
	TGRBeaconStatusReinitialized, // 再初期設定済み
	TGRBeaconStatusActive, // アクティブ
	TGRBeaconStatusInactive, // 休止中
	TGRBeaconStatusRemoved, // 撤去済み
	TGRBeaconStatusTerminated, // 終了
	TGRBeaconStatusUnknown, // 不明
	TGRBeaconStatusIBeaconCompatibleMode // iBeacon互換動作モード（Beaconを再起動しないと元の状態にもどりません）
};

/*!
 * TGRBattery
 */
typedef NS_ENUM(NSInteger, TGRBattery) {
	TGRBatteryUnknown, // 不明
	TGRBattery25, // 残り20%-0%
	TGRBattery50, // 残り40%-20%
	TGRBattery75, // 残り60%-40%
	TGRBattery100, // 残り100%-80%
	TGRBatteryFeed // 給電中
};

typedef NS_ENUM(NSInteger, TGRMode) {
    ModeTGR, // TGR
    ModeiBeacon, // iBeacon
    ModeSecureiBeacon, // secureiBeacon
    ModeLINE, // LINE
    ModeLINE_iBeacon, // LINE_iBeacon
    ModeLINE_SecureiBeacon, // LINE_SecureiBeacon
    ModeFLX, // FLX
    ModeiBeacon_FLX, // iBeacon_FLX
    ModeSecureiBeacon_FLX, // SecureiBeacon_FLX
    ModeUnKnown
};

/*!
 *  Beaconの各種情報を保持するBeaconクラスです。
 *  TGRBeaconManagerより取得します。
 *  @see TGRBeaconManager
 */
@interface TGRBeacon : NSObject<NSCoding>

- (void)encodeWithCoder:(NSCoder *)aCoder;
- (id)initWithCoder:(NSCoder *)aDecoder;
/*!
 *  @property Beacon識別子
 *
 *  @discussion Beaconに関連付けされたユニークな識別子です。
 */
@property (nonatomic, strong) NSUUID *identifier;

/*!
 *  @property デバイス名称
 */
@property (readonly, nonatomic) NSString *name;

/*!
 *  @property major
 */
@property (nonatomic, strong) NSNumber *major;

/*!
 *  @property minor
 */
@property (nonatomic, strong) NSNumber *minor;

/*!
 *  Proximity
 */
@property (nonatomic, nonatomic) TGRProximity proximity;

/*!
 *  Proximity
 */
@property (nonatomic, nonatomic) TGRProximity lastProximity;

/*!
 *  @property Beacon端末シリアルID (4bytes)
 */
@property (nonatomic, strong) NSString *serialId;


/*!
 *  @property IotSensor用TgrPacketAllByte
 */
@property (nonatomic, strong) NSString *tgrPacket;

/*!
 *  @property HWVersion(nRF chipVersion)
 */
@property (nonatomic, strong) NSString *hwVersion;


/*!
 *  @property Secure or Non-Secure
 */
@property (nonatomic, strong) NSNumber *isSecure;

/*!
 * @property Beacon論理ID (4bytes)
 */
@property (nonatomic, strong) NSNumber *beaconId;

/*!
 * @property GEOハッシュ値 (10bytes)
 */
@property (nonatomic, strong) NSString *geohash;

/*!
 * @property Service ID (2bytes)
 */
@property (nonatomic, strong) NSNumber *serviceId;

/*!
 * @property BeaconMode (1bytes)
 */
@property (nonatomic, nonatomic) TGRMode beaconMode;


/*!
 * @property ファームウェアVersion番号 (2bytes)
 */
@property (nonatomic, strong) NSNumber *firmwareVersion;

@property (nonatomic, assign) unsigned int vsalt;


/*!
 *  @property 電波送信強度です.
 *  0-8までの値が入ります。デフォルト値は7です。
 *  0 : -40 dBm (Min)
 *  1 : -30 dBm
 *  2 : -20 dBm
 *  3 : -16 dBm
 *  4 : -12 dBm
 *  5 : -8  dbm
 *  6 : -4  dbm
 *  7 : 0   dbm (Default)
 *  8 : 4   dbm (Max)
 */
@property (nonatomic, strong) NSNumber *txPower;

/*!
 *  @property アドバタイズメントの電波送信頻度（ms）です.
 *  最大値は、10秒（1000ms）まで。最小値は、0.2秒（20ms）までです。
 */
@property (nonatomic, strong) NSNumber *txFrequency;


/*!
 *  @property LINE アドバタイズメントの電波送信頻度（ms）です.
 *  基本的には76.25である @15
 */
@property (nonatomic, strong) NSNumber *txLINEFrequency;

/*!
 *  @property Beaconのステータスです.
 */
@property (nonatomic, assign) TGRBeaconStatus status;

/*!
 *  @property BeaconのBatteryステータスです.
 */
@property (nonatomic, nonatomic) TGRBattery battery;


/*!
 *  @property BeaconのnewerBatteryステータスです.
 */
@property (nonatomic, nonatomic) NSNumber *newerBattery;

/*!
 *  @property 信号強度（RSSI）です。
 */
@property (nonatomic, strong) NSNumber *rssi;

/*!
 *  @property Bluetoothペリフェラルのインスタンスです。
 *
 *  @discussion BeaconManagerで操作します。
 */
@property (nonatomic, strong) CBPeripheral *peripheral;

/*!
 *  @property Advertisementデータです。
 */
@property (nonatomic, strong) NSDictionary *advertisementData;

/*!
 * 前回検出時より近づいている場合 YESを返します
 */
- (BOOL) isCloser;

/*!
 * 前回検出時より遠のいている場合 YESを返します
 */
- (BOOL) isAway;


@property (nonatomic, strong) CLBeacon * baseCLBeacon;


@property (nonatomic, assign) BOOL changed;

@property (nonatomic, strong) NSUUID *flxIdentifier;

- (instancetype) initWithCLBeacon:(CLBeacon *)clBeacon;
- (instancetype) initWithProximityUUID:(NSUUID *)uuid major:(NSNumber *)major minor:(NSNumber *)minor peripheral:(CBPeripheral *)peripheral;
- (instancetype) initWithName:(NSString *)name proximityUUID:(NSUUID *)uuid major:(NSNumber *)major minor:(NSNumber *)minor;

- (NSArray *) createUpdatePayload;
- (void) keepLastSettings;
- (BOOL) isIdentifierEqual:(id)object;
- (void) update:(TGRBeacon *)beacon;

+ (NSString *)proximityString:(TGRProximity)proximity;
+ (NSString *)statusString:(TGRBeaconStatus)status;
+ (NSString *)batteryString:(TGRBattery)battery;
+ (NSString *)txPowerString:(NSNumber *)num;
+ (NSString *)txFreqString:(NSNumber *)num;

@end
