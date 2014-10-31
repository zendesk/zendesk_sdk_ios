//
//  ZDKHelpCenterSearchProvider.h
//  ZendeskSDK
//
//  Created by Zendesk on 30/09/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import "ZDKHelpCenterProvider.h"

@interface ZDKHelpCenterSearchProvider : ZDKHelpCenterProvider

/**
 * Search for articles in help centre.
 *
 * @param callback This block is called when the articles are retireved from help center.
 * @param query The query sent to help center.
 */
+ (void) items:(ZDKHelpCenterCallback)callback forQuery:(NSString *)query;


@end
