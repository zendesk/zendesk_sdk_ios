/*
 *
 *  ZDKRequestProvider.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 08/11/2014.  
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
#import "ZDKProvider.h"
#import "ZDKRequestUpdatesProtocol.h"

@class ZDKCommentsResponse, ZDKComment, ZDKRequest, ZDKCreateRequest, ZDKTicketForm, ZDKRequestUpdates;


/**
 *  Block defined for callback to be used for handling async server responses for fetching a single request.
 *
 *  @since 1.2.0.1
 *
 *  @param request ZDKRequest object as a result of the API request sent to a Zendesk instance, can be nil on error.
 *  @param error   NSError returned as a result of any errors taking place when the request is executed, can be nil on success.
 */
typedef void (^ZDKRequestCallback)(ZDKRequest *request, NSError *error);

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

/**
 *  Callback for request updates provider method.
 *
 *  @param requestUpdates model containing any updates.
 *  @param error NSError returned as a result of any errors taking place when the request is executed, can be nil on success.
 *  @since 1.10.0.1
 */
typedef void (^ZDKRequestUpdatesCallback)(ZDKRequestUpdates *requestUpdates, NSError *error);

/**
 *  Callback for ticket form request
 *
 *  @param ticketForms The updated user tags
 *  @param error    An error object. Nil if no error occurred.
 *
 *  @since 1.9.0.1
 */
typedef void (^ZDKTicketFormCallback)(NSArray<ZDKTicketForm*> *ticketForms, NSError *error);


@interface ZDKRequestProvider : ZDKProvider


/**
 *  Calls a request service to create a request on behalf of the end user.
 *
 *  @param request  Request model object.
 *  @param callback callback invoked in response to remote API invocation.
 *
 *  @since 1.3.0.1
 */
- (void) createRequest:(ZDKCreateRequest*)request
          withCallback:(ZDKCreateRequestCallback)callback;


/**
 *  Gets the request specified by the ID.
 *
 *  @since 1.2.0.1
 *
 *  @param requestId  The ID of a request in Zendesk.
 *  @param callback   The callback to invoke which will return a ZDKRequest object.
 */
- (void) getRequestById:(NSString*)requestId withCallback:(ZDKRequestCallback)callback;

/**
 *  Gets all requests that user has opened.
 *  It will also get an access token if one has not been previously stored.
 *  If you are using anonymous identities we will check to see if you have any stored request IDs.
 *  This is how requests work when dealing with anonymous identities. If you do have stored request
 *  IDs we will fetch these requests from your Zendesk instance. If you do not have any stored request
 *  IDs we will skip the network call and return an empty list of Requests.
 *
 *  @param callback invoked in response to remote API invocation
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
 *  @param callback  Callback that will deliver a ZDKComment
 */
- (void) addComment:(NSString *) comment forRequestId:(NSString *) requestId withCallback:(ZDKRequestAddCommentCallback) callback;


/**
 * Gets the ticket froms
 * Only the first 5 ticket form Ids will be fetched.
 *
 *  @param callback The callback that is invoked when a request is either successful or has error.
 *
 *  @since 1.9.0.1
 */
- (void)getTicketFormWithIds:(NSArray<NSNumber*>*)ticketFormIds callback:(ZDKTicketFormCallback)callback;

/**
 * Add a comment message to a request with attachments on behalf of the end-user.
 * It will also get an access token if one has not been previously stored.
 *
 *  @param comment   The text of the comment to create
 *  @param requestId Id of a request to add this comment to
 *  @param attachments List of ZDKUploadResponse objects. Can be nil
 *  @param callback  Callback that will deliver a ZDKComment.
 */
- (void) addComment:(NSString *) comment
       forRequestId:(NSString *) requestId
        attachments:(NSArray *) attachments
       withCallback:(ZDKRequestAddCommentCallback) callback;


/**
 *  Gets details of any updates to requests for this device.
 *
 *  `ZDKRequestUpdates` are cached for up to one hour. Subsequent calls to this method within
 *  the hour will return the same object without querying the network. Calling this method once
 *  the hour has expired will query the network again, and cache the new results for the next
 *  hour.
 *
 *  If using the Zendesk UI, viewing a request will update the cached `ZDKRequestUpdates`
 *  to remove the viewed request. If using the providers only, a request can be removed from
 *  the cached `ZDKRequestUpdates` by calling `markRequestAsRead:` on the returned 
 *  `ZDKRequestUpdatesProtocol` with the request ID.
 *
 *  It is important to note the difference in behaviour of this method users using
 *  `ZDKAnonymousIdentity` versus users using `ZDKJwtIdentity`. For an
 *  `ZDKAnonymousIdentity`, this method will only fetch updates
 *  for requests which were created from this device (since those are all an Anonymous user
 *  has access to). However, a `ZDKJwtIdentity` will fetch all of
 *  the user's open requests, regardless of where they were created. Any request created on another
 *  channel is unknown to this instance of the Support SDK, and as such it will show in the
 *  resulting `ZDKRequestUpdates` with all of its comments counting as updates.
 *
 *  @since 1.10.0.1
 *
 *  @param callback supplies a ZDKRequestUpdates object if successful, otherwise an NSError is provided.
 *  @return An object which should be retained and used to signal when a user has viewed a request with updates.
 */
- (id<ZDKRequestUpdatesProtocol>) getUpdatesForDevice:(ZDKRequestUpdatesCallback)callback;

@end
