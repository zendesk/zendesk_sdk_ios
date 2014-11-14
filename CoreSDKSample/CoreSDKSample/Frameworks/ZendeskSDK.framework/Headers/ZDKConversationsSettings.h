//
//  ZDKConversationsSettings.h
//  ZendeskSDK
//
//  Created by Zendesk on 16/10/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZDKConversationsSettings : NSObject


/**
 * enabled defines if the conversations component is enabled or not
 */
@property (nonatomic, readonly) BOOL enabled;


/**
 * initWithDictionary, passing the NSDictionary of Conversations settings received from the server
 */
- (id) initWithDictionary:(NSDictionary *)dictionary ;

@end
