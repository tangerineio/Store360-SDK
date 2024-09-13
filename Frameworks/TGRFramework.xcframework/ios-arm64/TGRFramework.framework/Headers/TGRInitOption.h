//
//  TGRInitOption.h
//  TGRClient
//
//  Created by Steel on 1/19/28 H.
//  Copyright © 28 Heisei Tangerine Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TGRConstants.h"

@interface TGRInitOption : NSObject
@property (nonatomic ) NSString* devId;
@property (nonatomic ) NSString* appId;
@property (nonatomic ) NSString* serviceId;
@property (nonatomic ) BOOL enableADID;
@property (nonatomic ) BOOL enableNotify;

@property (nonatomic ) TGRActionType actionType;

- (instancetype)initWithAppId:(NSString*)appId devId:(NSString*)devId serviceId:(NSString*)serviceId enableADID:(BOOL)enableADID enableNotify:(BOOL)enableNotify;


@end
