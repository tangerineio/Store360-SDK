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
@property (nonatomic, strong) NSString * _Nonnull devId;
@property (nonatomic, strong) NSString * _Nonnull appId;
@property (nonatomic, strong) NSString * _Nonnull serviceId;
@property (nonatomic ) BOOL enableADID;
@property (nonatomic ) BOOL enableNotify;

@property (nonatomic ) TGRActionType actionType;

- (instancetype _Nonnull )initWithAppId:(NSString * _Nonnull)appId
                        devId:(NSString * _Nonnull)devId
                    serviceId:(NSString * _Nonnull)serviceId
                   enableADID:(BOOL)enableADID
                 enableNotify:(BOOL)enableNotify;


@end
