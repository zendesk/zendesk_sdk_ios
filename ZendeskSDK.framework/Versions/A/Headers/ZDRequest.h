//
//  ZDRequest.h
//  ZDAPI
//
//  Created by Zendesk on 13/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import "ZDModelObject.h"
#import "ZDUsers.h"


/**
 * Object representing a Zendesk end user request.
 */
@interface ZDRequest : ZDModelObject


/**
 * Reference to the user cache.
 */
@property (nonatomic, strong) ZDUsers *users;

/**
 * The id of this request in Zendesk.
 */
@property (nonatomic, strong) NSNumber *requestId;

/**
 * The id of the requester in Zendesk.
 */
@property (nonatomic, strong) NSNumber *requesterId;

/**
 * Request status.
 */
@property (nonatomic, strong) NSString *status;

/**
 * The subject of the request, if subject is enabled in the account and if a subject was entered.
 */
@property (nonatomic, strong) NSString *subject;

/**
 * The original request.
 */
@property (nonatomic, strong) NSString *requestDescription;

/**
 * The timestamp of the request creation.
 */
@property (nonatomic, strong) NSDate *createdAt;

/**
 * The timestamp of the last update event.
 */
@property (nonatomic, strong) NSDate *updateAt;

/**
 * The timestamp of the last agent update to this request.
 */
@property (nonatomic, strong) NSDate *lastAgentUpdate;

/**
 * The last time this request was view by this client.
 */
@property (nonatomic, strong) NSDate *lastViewed;

/**
 * The list of comments for this request.
 */
@property (nonatomic, strong) NSArray *comments;


/**
 * Init with dictionary from API response.
 *
 * @param account the account object with the details necessary to form requests
 * @param dispatcher the dispatcher to be used for sending requests
 * @param userCache the user cache
 * @param dict the dictionary generated from the JSON API response
 */
- (instancetype) initWithAccount:(ZDAccount*)theAccount
                      dispatcher:(ZDDispatcher*)theDispatcher
                       userCache:(ZDUsers*)userCache
                         andDict:(NSDictionary*)dict;


/**
 * Refresh the comments for this request.
 *
 * @param successBlock to be executed upon success, the result object will be the request object with it's comments
 * @param errorBlock to be executed upon error
 */
- (void) refreshComments:(ZDAPISuccess)successBlock
                 onError:(ZDAPIError)errorBlock;


/**
 * Submit a new comment to the server.
 * 
 * @param comment the comment to add
 * @param successBlock to be executed upon success, the result object will be the request object with it's comments
 * @param errorBlock to be executed upon error
 */
- (void) addComment:(NSString*)comment
          onSuccess:(ZDAPISuccess)successBlock
            onError:(ZDAPIError)errorBlock;


@end

