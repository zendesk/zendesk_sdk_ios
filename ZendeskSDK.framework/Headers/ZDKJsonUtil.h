//
//  ZDKJsonUtil.h
//  ZendeskSDK
//
//  Created by Zendesk on 09/11/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZDKJsonUtil : NSObject

/**
 * Checks the return value for NSNull and converts to nil if found.
 *
 * @param json the JSON dictionary from which to get the value
 * @param key the key of the object to be retrieved
 * @return the value if found and not NSNull, otherwise nil
 */
+ (id) cleanJSONVal:(NSDictionary*)json key:(NSString*)key;


/**
 * Check the value for NSNull.
 *
 * @param val the value to be checked
 * @return the value if not NSNull, otherwise nil
 */
+ (id) cleanJSONVal:(id)val;


@end
