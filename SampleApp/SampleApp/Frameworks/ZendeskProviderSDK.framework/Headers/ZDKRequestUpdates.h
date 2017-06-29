/*
 *
 *  ZDKRequestUpdates.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 19/05/2017.
 *
 *  Copyright (c) 2017 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */


#import <Foundation/Foundation.h>


/**
 Returned by ZDKRequsetProvider method getUnreadCount.
 */
@interface ZDKRequestUpdates : NSObject


/**
 *  This will be true if there are any unread comments on for the current
 *  identity, false otherwises.
 *
 *  @since 1.10.0.1
 */
@property (nonatomic, readonly) BOOL hasUpdates;

/**
 *  Returns an aggregate of unread comment counts.
 *
 *  @since 1.10.0.1
 */
@property (nonatomic, readonly) NSNumber  *updateCount;


/**
 *  A map of request id to unread count. This will be empty if 
 *  hasUnread is false, or totalUnreadCount is 0
 *
 *  @since 1.10.0.1
 */
@property (nonatomic, copy, readonly) NSMutableDictionary<NSString*, NSNumber*> *requestsWithUpdates;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end
