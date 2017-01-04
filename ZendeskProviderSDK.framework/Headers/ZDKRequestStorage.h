/*
 *
 *  ZDKRequestStorage.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 25/11/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>

@interface ZDKRequestStorage : NSObject


/**
 *  Add a requestIdentifier to be stored as a result of a request being created
 *
 *  @param requestIdentifier NSString of request id sourced from creating a new request
 */
- (void) storeRequestIdentifier:(NSString *) requestIdentifier;


/**
 *  Return an NSArray of Strings of request ids that have been stored on this device
 *
 *  @return NSArray of Strings
 */
- (NSArray *) getRequestIdentifiers;


/**
 *  Return an NSArray of Strings of request ids that have been stored on this device
 *
 *  @return NSArray of Strings
 *
 *  @since 1.6.0.1
 */
- (NSArray *) requestIdentifiers;


/**
 *  Gets the last known comment count for a request.
 *
 *  @param requestId The id of the request.
 *
 *  @return The comment count for the request, nil if not known.
 *
 *  @since 1.4.1.1
 */
- (NSNumber *) clientCommentCountForRequest:(NSString *)requestId;


/**
 *  Set the comment count for a request.
 *
 *  @param requestId The id of the request.
 *  @param count The count to store.
 *
 *  @since 1.4.1.1
 */
- (void) setClientCommentCountForRequest:(NSString *)requestId count:(NSNumber *)count;


/**
 * Deletes ALL storage
 */
- (void) deleteStoredData;

@end
