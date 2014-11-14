//
//  ZDKContactUsSettings.h
//  ZendeskSDK
//
//  Created by Zendesk on 16/10/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZDKContactUsSettings : NSObject

/**
 * tags is a list of tags that should be included as part of the ticket creation
 */
@property (nonatomic, readonly) NSArray *tags;

/**
 * initWithDictionary, passing the NSDictionary of Contact Us settings received from the server
 */
- (id) initWithDictionary:(NSDictionary *)dictionary ;

@end
