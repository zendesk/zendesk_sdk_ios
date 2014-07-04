//
//  ZDPersistentModelObject.h
//  ZDAPI
//
//  Created by Zendesk on 13/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import "ZDModelObject.h"


/**
 * Extention for the model object providing persistence.
 */
@interface ZDPersistentModelObject : ZDModelObject


#pragma mark persistence


/**
 * Store the data provided by dataToPersist: now.
 */
- (void) storeData;


@end

