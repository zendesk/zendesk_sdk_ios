//
//  ZDAPIConstants.h
//  ZDAPI
//
//  Created by Zendesk on 13/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import "ZDModelObject.h"


/**
 * Notification for triggering storage of requests.
 */
static NSString *const ZDAPI_RequestsUpdated = @"ZDAPI_RequestsUpdated";

/**
 * Notification for triggering storage of users.
 */
static NSString *const ZDAPI_UsersUpdated = @"ZDAPI_UsersUpdated";

/**
 * Notification that a comment is about to be submitted.
 */
static NSString *const ZDAPI_CommentSubmissionStarting = @"ZDAPI_CommentSubmissionStarting";

/**
 * Notification that a comment has been successfully submitted.
 */
static NSString *const ZDAPI_CommentSubmissionSuccess = @"ZDAPI_CommentSubmissionSuccess";

/**
 * Notification that there was an error during comment submission.
 */
static NSString *const ZDAPI_CommentSubmissionError = @"ZDAPI_CommentSubmissionError";

/**
 * Notification that a request is about to be submitted.
 */
static NSString *const ZDAPI_RequestSubmissionStarting = @"ZDAPI_RequestSubmissionStarting";

/**
 * Notification that a request has been successfully submitted.
 */
static NSString *const ZDAPI_RequestSubmissionSuccess = @"ZDAPI_RequestSubmissionSuccess";

/**
 * Notification that there was an error during request submission.
 */
static NSString *const ZDAPI_RequestSubmissionError = @"ZDAPI_RequestSubmissionError";

/**
 * Notification that the request list is about to be retrieved.
 */
static NSString *const ZDAPI_RequestsStarting = @"ZDAPI_RequestsStarting";

/**
 * Notification that the request list was successfulyl retrieved.
 */
static NSString *const ZDAPI_RequestsSuccess = @"ZDAPI_RequestsSuccess";

/**
 * Notification that there was an error while retrieving the request list.
 */
static NSString *const ZDAPI_RequestsError = @"ZDAPI_RequestsError";

