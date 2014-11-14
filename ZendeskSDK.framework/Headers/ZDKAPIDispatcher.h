//
//  ZDKAPIDispatcher.h
//  ZendeskSDK
//
//  Created by Zendesk on 22/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZDKDeviceInfo.h"
#import "ZDKAccount.h"
#import "ZDKDispatcher.h"
#import "ZDKDispatcherDelegate.h"
#import "ZDKRequest.h"
#import "ZDKComment.h"

/**
 * ZDKAPI is the primary access point for API requests.
 */
@interface ZDKAPIDispatcher : ZDKDispatcher <ZDKDispatcherDelegate>

+ (instancetype) instance;

@end

