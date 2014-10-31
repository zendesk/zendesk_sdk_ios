//
//  ZDKRequests.h
//  ZendeskSDK
//
//  Created by Zendesk on 13/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "ZDKModelObject.h"
#import "ZDKUserContainer.h"


/**
 * The requests for the logged in user.
 */
@interface ZDKRequestContainer : ZDKModelObject


/**
 * Reference to the user cache.
 */
@property (nonatomic, strong) ZDKUserContainer *users;


/**
 * The list of user requests.
 */
@property (nonatomic, strong) NSArray *requests;


/**
 * Initialise the model object with the account details ands the dispatcher to be used for requests.
 *
 * @param theAccount the account object with the details necessary to form requests
 * @param theDispatcher the dispatcher to be used for sending requests
 * @param userCache the user cache
 */
- (instancetype) initWithAccount:(ZDKAccount*)theAccount
                      dispatcher:(ZDKDispatcher*)theDispatcher
                    andUserCache:(ZDKUserContainer*)userCache;


/**
 * Refresh the list of requests.
 *
 * @param successBlock to be executed upon success, the result object will be the request object with it's comments
 * @param errorBlock to be executed upon error
 */
- (void) refresh:(ZDKAPISuccess)successBlock
         onError:(ZDKAPIError)errorBlock;


/**
 * Clear all data, both in memory and persistence.
 */
- (void) clear;


@end

