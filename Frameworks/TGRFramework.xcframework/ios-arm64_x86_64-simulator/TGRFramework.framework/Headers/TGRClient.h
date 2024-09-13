//
//  TGRClient.h
//  TGRClient
//
//  Created by DAISUKE KIMURA on 2014/03/05.
//  Copyright (c) 2014年 Tangerine Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Tangerine.h"
#import "TGRConstants.h"
#import <CoreData/CoreData.h>
#import "TGRInitOption.h"
#import <CoreBluetooth/CoreBluetooth.h>
#import <UserNotifications/UserNotifications.h>
#import <AdSupport/AdSupport.h>

@protocol TGRClientDelegate <NSObject>

@optional
- (void)didEnterWithParams:(NSDictionary * _Null_unspecified)params rssi:(NSNumber * _Null_unspecified)rssi;
- (void)didExitWithParams:(NSDictionary * _Null_unspecified)params rssi:(NSNumber * _Null_unspecified)rssi;
- (void)didFailWithErrorType:(TGRErrorType)errorType error:(NSError * _Null_unspecified)error;
- (void)requestImageWithURL:(NSURL * _Nullable)url completion:(void (^ _Nullable)(UIImage * _Nullable image, NSError * _Nullable error))completionHandler;
- (void)getURLSchemeinWebview:(NSURLRequest * _Null_unspecified)request;
- (void)tappedNotificationWithParam:(NSDictionary * _Null_unspecified)action enterFlag:(BOOL)enterFlag beacon:(TGRBeacon * _Null_unspecified)beacon;
- (void)receiveNotificationParam:(NSDictionary * _Null_unspecified)action beacon:(TGRBeacon * _Null_unspecified)beacon;
- (void)getBarCodeData:(NSString * _Null_unspecified)BarcodeValue err:(NSError * _Null_unspecified)error;
@end


@interface TGRClient : NSObject<CBCentralManagerDelegate>

@property (nonatomic, weak) id<TGRClientDelegate> _Nullable delegate;
@property (nonatomic, strong) CBCentralManager * _Nonnull centralManager;


//init
- (TGRClient * _Nonnull)initWithOption:(TGRInitOption * _Nonnull)optionForInit delegate:(id<TGRClientDelegate> _Nullable)delegate;

//process
- (void)startMonitoring;
- (void)stopMonitoring;
- (void)logout;

//uuid
- (NSString * _Nonnull)uniqueIdentifier;
- (NSString * _Nonnull)refreshHandsetId;

//log
- (void)sendAppData:(NSDictionary * _Nonnull)eventData;
- (void)sendLogEvent:(TGRLogEvent)eventId;
- (void)sendAppEvent:(NSString * _Nonnull)event;
- (void)sendLogEventWithString:(NSString * _Nonnull)eventString;
- (void)setAppUserId:(NSString * _Nonnull)userId;
- (void)getNotifications:(NSString * _Nonnull)identifier;
- (void)removeNotifiedBanner:(NSString * _Nonnull)identifier;


//Settings
- (void)setNotifyEnable:(BOOL)enable;
- (void)showAppWebView:(NSString * _Nonnull)url needBack:(BOOL)needBack needClose:(BOOL)needClose viewConfiguration:(NSDictionary * _Nullable)viewConfiguration;

//idfa
//- (NSString *)identifierForAdvertising;
//- (NSString *)getIDFA;

//BarScan Request
-(void)scanBarcode;

//GetCurrentSite
- (NSDictionary * _Nullable)getCurrentSite;
- (NSDictionary * _Nullable)getNearbyBeacons;
- (void)showInStoreButton;
- (void)hideInStoreButton;


//Handler For App received TGRNotification
- (void)fromAppReceivedNotification:(UNNotificationResponse * _Nonnull)response;

- (void)openInStoreMenuWithURL:(nullable NSString *)urlString;

//GeoFence Operations
-(void)stopSignificantLocationMonitoring;

//QRcode SDK2.5.0
- (void)showQrBeacon:(NSString *_Nonnull)url urlSchem:(NSString *_Nonnull)urlSchem;
- (void)dummySendActionDetail:(NSNumber *_Nonnull)beaconId;

@end


