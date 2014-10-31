//
//  ZDKUsers.h
//  ZendeskSDK
//
//  Created by Zendesk on 13/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "ZDKModelObject.h"
#import "ZDKUser.h"


/**
 * Cache of Zendesk users backed by persistence.
 */
@interface ZDKUserContainer : ZDKModelObject


/*
 * Get the user record for the requested id, if the user is unknown then a new record will be created and returned.
 *
 * @param userId the is of the user to retrieve
 * @return the user record
 */
- (ZDKUser*) getUser:(NSNumber*)userId;


/**
 * Clear all data, both in memory and persistence.
 */
- (void) clear;


@end

