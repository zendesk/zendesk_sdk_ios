//
//  ZDRequests.h
//  ZDAPI
//
//  Created by Zendesk on 13/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "ZDPersistentModelObject.h"
#import "ZDUsers.h"


/**
 * The requests for the logged in user.
 */
@interface ZDRequests : ZDPersistentModelObject


/**
 * Reference to the user cache.
 */
@property (nonatomic, strong) ZDUsers *users;


/**
 * The list of user requests.
 */
@property (nonatomic, strong) NSArray *requests;


/**
 * Initialise the model object with the account details ands the dispatcher to be used for requests.
 *
 * @param account the account object with the details necessary to form requests
 * @param dispatcher the dispatcher to be used for sending requests
 * @param userCache the user cache
 */
- (instancetype) initWithAccount:(ZDAccount*)theAccount
                      dispatcher:(ZDDispatcher*)theDispatcher
                    andUserCache:(ZDUsers*)userCache;


/**
 * Refresh the list of requests.
 *
 * @param successBlock to be executed upon success, the result object will be the request object with it's comments
 * @param errorBlock to be executed upon error
 */
- (void) refresh:(ZDAPISuccess)successBlock
         onError:(ZDAPIError)errorBlock;


@end

