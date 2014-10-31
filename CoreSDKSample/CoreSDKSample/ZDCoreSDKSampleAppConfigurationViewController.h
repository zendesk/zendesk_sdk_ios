//
//  ZDCoreSDKSampleAppConfigurationViewController.h
//  CoreSDKSample
//
//  Created by Zendesk on 11/10/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ZendeskSDK/ZendeskSDK.h>

@protocol ZDCoreSDKAppCondigurationDelegate <NSObject>

- (void) configuration:(NSString *) url withAppId:(NSString *) appId withClientId:(NSString *) clientId withUserId:(NSString *) userId;

@end

@interface ZDCoreSDKSampleAppConfigurationViewController : ZDKUIViewController <UITextFieldDelegate>

@property (nonatomic, strong) id <ZDCoreSDKAppCondigurationDelegate> delegate;

@end
