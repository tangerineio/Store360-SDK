//
//  TGRConstants.h
//  TGRClient
//
//  Created by Daisuke Kimura on 2014/09/12.
//  Copyright (c) 2014年 Tangerine Inc. All rights reserved.
//

#ifndef TGRClient_TGRConstants_h
#define TGRClient_TGRConstants_h

/*
 From SDK2 ActionType change to the below list
 
 App – Return Action Parameters
 App – Return URL Scheme
 SDK to Launch Browser
 SDK to Launch other App with URL Scheme
 SDK to Launch Tangerine Action Service
 Eddystone URL
 
 */
typedef enum : NSInteger {
    TGRActionTypeEvent = 0,
    TGRActionTypeAction,
    TGRActionTypeAll,
    TGRActionTypeActionParam,
    TGRActionTypeURLScheme,
    TGRActionTypeLaunchBrowser,
    TGRActionTypeLaunchOtherAPP,
    TGRActionTypeLaunchMicroService,
    TGRActionTypeEddystoneURL,
} TGRActionType;

typedef enum : NSInteger {
    TGRLogTypeBeacon = 0,
    TGRLogTypeApplicatioin,
} TGRLogType;

typedef enum : NSInteger {
    TGRLogEventUserDefined = 0,
    TGRLogEventCustomerId,
    TGRLogEventActionResponded
} TGRLogEvent;

typedef enum : NSInteger {
    TGRErrorTypeNetworkAuth = 0,
    TGRErrorTypeNetworkUuidList,
    TGRErrorTypeNetworkActionList,
    TGRErrorTypeNetworkActionDetail,
    TGRErrorTypeNetworkActionImage,
    TGRErrorTypeNetworkLogApp,
    TGRErrorTypeNetworkLogBeacon,
    TGRErrorTypeNetworkLogGeoFence,
    TGRErrorTypeNetworkActionListRefreshIntervalTime,
    TGRErrorTypeLocation,
    TGRErrorTypeBeacon,
    TGRErrorTypeNoError,
    TGRErrorTypeRegionMonitoring,
    TGRErrorTypeOpenInstoreMenu
} TGRErrorType;

#endif
