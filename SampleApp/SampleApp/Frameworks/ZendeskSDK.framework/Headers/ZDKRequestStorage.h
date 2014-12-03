/*
 *
 *  ZDKRequestStorage.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 25/11/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
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
 *  Gets timestamp of when the request was last read
 *
 *  @param requestId The request id
 *
 *  @return NSDate of the last time it was read, nil if no date found
 */
- (NSDate *) lastReadDateUsingRequestId:(NSString *)requestId;

/**
 *  Stores a time when this request was last read
 *
 *  @param requestId The id of the request
 *  @param date      The timestamp that the request was last read
 */
- (void) setLastReadDateUsingRequestId:(NSString *)requestId andDate:(NSDate *)date;

/**
 * Deletes ALL storage
 */
- (void) deleteStoredData;

@end
