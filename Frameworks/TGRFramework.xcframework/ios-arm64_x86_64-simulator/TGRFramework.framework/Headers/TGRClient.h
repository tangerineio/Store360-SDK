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
//2.1
- (void)didEnterWithParams:(NSDictionary *)params rssi:(NSNumber *)rssi;
- (void)didExitWithParams:(NSDictionary *)params rssi:(NSNumber *)rssi;
- (void)didFailWithErrorType:(TGRErrorType)errorType error:(NSError *)error;
- (void)requestImageWithURL:(NSURL *)url completion:(void (^)(UIImage *image, NSError *error))completionHandler;
- (void)getURLSchemeinWebview:(NSURLRequest *)request;
- (void)tappedNotificationWithParam:(NSDictionary *)action enterFlag:(BOOL)enterFlag beacon:(TGRBeacon *)beacon;
- (void)receiveNotificationParam:(NSDictionary *)action beacon:(TGRBeacon *)beacon;
- (void)getBarCodeData:(NSString *)BarcodeValue err:(NSError *)error;
@end

@interface TGRClient : NSObject<CBCentralManagerDelegate>

@property (nonatomic, weak) id<TGRClientDelegate> delegate;
@property (nonatomic, strong) CBCentralManager *centralManager;

//init
- (TGRClient *)initWithOption:(TGRInitOption*)optionForInit delegate:(id<TGRClientDelegate>) delegate;
//process
- (void)startMonitoring;
- (void)stopMonitoring;
- (void)logout;
//uuid
- (NSString *)uniqueIdentifier;
//log
- (void) sendAppData:(NSDictionary *)eventData;
- (void)sendLogEvent:(TGRLogEvent)eventId;
- (void)sendAppEvent:(NSString *)event;
- (void)sendLogEventWithString:(NSString *)eventString;
- (void)setAppUserId:(NSString *)userId;
- (void)getNotifications:(NSString *)identifier;
- (void)removeNotifiedBanner:(NSString *)identifier;
//Settings

- (void)setNotifyEnable:(BOOL)enable;
- (void)showAppWebView:(NSString*)url needBack:(BOOL)needBack needClose:(BOOL)needClose viewConfiguration:(NSDictionary *)viewConfiguration;

//idfa
- (NSString *)identifierForAdvertising;
- (NSString *)getIDFA;

//BarScan Request
-(void)scanBarcode;

//GetCurrentSite
-(NSDictionary *)getCurrentSite;
-(void)showInStoreButton;
-(void)hideInStoreButton;


//Handler For App received TGRNotification
-(void)fromAppReceivedNotification:(UNNotificationResponse *)response;

//GeoFence Operations
-(void)stopSignificantLocationMonitoring;


@end


