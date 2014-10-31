//
//  ZDKHelpCenterProvider.h
//  ZendeskSDK
//
//  Created by Zendesk on 11/09/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * Callback block.
 *
 */
typedef void (^ZDKHelpCenterCallback)(NSArray *items, NSError *error);



@interface ZDKHelpCenterProvider : NSObject


/**
 * Get a list of items from help centre.
 *
 * @param callback This block is called when the items are retireved from help center.
 * @param parentId The parent ID of the items, or nil if there is no parent.
 */
+ (void) items:(ZDKHelpCenterCallback)callback parent:(NSString *)parentId;


/**
 * Get a list of items from help centre.
 *
 * @return A base request with accept and user agent headers set.
 */
+ (NSMutableURLRequest *) baseRequest;


/**
 * Adds a resource to the base Help Centre domain.
 *
 * @param resource A resource endpoint.
 * @return A URL for the resource provided.
 */
+ (NSURL *) helpCenterURLFromString:(NSString *)resource;


/**
 * Current issues with locale returning en-us for convienence
 *
 */
+ (NSString *) currentLocale;


@end
