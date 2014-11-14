//
//  ZDKETag.h
//  ZendeskSDK
//
//  Created by Zendesk on 01/09/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZDKDispatcherResponse;

@interface ZDKETag : NSObject

#pragma mark etags


/**
 * Adds the etag to the request if one is known.
 *
 * @param request the request to which the etag will be added
 */
+ (void) addEtagToRequest:(NSMutableURLRequest*)request;



/**
 * Store the etag from the request and check if the response is 'unmodified'
 *
 * @param response the response data
 * @return YES if the response was 'unmodified' otherwise NO
 */
+ (BOOL) unmodified:(ZDKDispatcherResponse*)response;



/**
 * Get an ETag for a url if it is known.
 *
 * @param url the URL for the request or response.
 * @return An ETag or nil if none was found.
 */
+ (NSString *) eTagForURL:(NSURL*)url;


@end
