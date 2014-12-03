/*
 *
 *  ZDKRequestProvider.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 08/11/2014.  
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
@class ZDKCommentsResponse,ZDKComment;
/**
 *  Block defined for callback to be used for handling async server responses for fetching a list of requests
 *
 *  @param items array of items returned as a result of the API request sent to a Zendesk instance
 *  @param error NSError returned as a result of any errors taking place when the request is executed, can be nil on success
 */
typedef void (^ZDKRequestListCallback)(NSArray *items, NSError *error);

/**
 *  Block defined for callback to be used for handling async server responses for fetching a list of comments
 *
 *  @param commentsWithUsers array of ZDKCommentWithUser objects as a result of the API request sent to a Zendesk instance, can be nil on error
 *  @param error NSError returned as a result of any errors taking place when the request is executed, can be nil on success
 */
typedef void (^ZDKRequestCommentListCallback)(NSArray *commentsWithUsers, NSError *error);

/**
 *  Block defined for callback to be used for handling async server responses for adding a comment to a request
 *
 *  @param comment ZDKComment object as a result of the API request sent to a Zendesk instance, can be nil on error
 *  @param error   NSError returned as a result of any errors taking place when the request is executed, can be nil on success
 */
typedef void (^ZDKRequestAddCommentCallback)(ZDKComment *comment, NSError *error);

/**
 *  Block defined for a callback to be used for handling async server response for creating a request
 *
 *  @param result id object as a result of the API request sent to a Zendesk instance, can be nil on error
 *  @param error  NSError returned as a result of any errors taking place when the request is executed, can be nil on success
 */
typedef void (^ZDKCreateRequestCallback)(id result, NSError *error);

@interface ZDKRequestProvider : NSObject

/**
 *  Calls a request service to create an anonymized request on behalf of the end-user.C
 *
 *  @param subject     Message describing the subject of the request
 *  @param description More detailed description of a problem
 *  @param tags        List of label that mark the request
 *  @param callback    callback invoked in response to remote API invokation
 */
- (void) createRequestWithSubject:(NSString *)subject
                 andDescription:(NSString *)description
                        andTags:(NSArray *)tags
                    andCallback:(ZDKCreateRequestCallback) callback;

/**
 * Gets all requests that user has opened.
 * It will also get an access token if one has not been previously stored.
 *
 *  @param callback invoked in response to remote API invokation
 */
- (void) getAllRequestsWithCallback:(ZDKRequestListCallback) callback;

/**
 * Filters requests that user has opened by a status.
 * It will also get an access token if one has not been previously stored.
 *
 *  @param status   A comma separated list of status to filter the results by
 *  @param callback The callback to invoke which will return a list of requests
 */
- (void) getRequestsByStatus:(NSString *) status withCallback:(ZDKRequestListCallback) callback;

/**
 * Gets all comments for a request.
 * It will also get an access token if one has not been previously stored.
 *
 *  @param requestId Id of a request
 *  @param callback  Callback that will deliver a CommentResponse model
 */
- (void) getCommentsWithRequestId: (NSString *) requestId withCallback:(ZDKRequestCommentListCallback) callback;

/**
 * Add a comment message to a request.
 * It will also get an access token if one has not been previously stored.
 *
 *  @param comment   The text of the comment to create
 *  @param requestId Id of a request to add this comment to
 *  @param callback  Callback that will deliver a
 */
- (void) addComment:(NSString *) comment forRequestId:(NSString *)requestId withCallback:(ZDKRequestAddCommentCallback) callback;


@end
