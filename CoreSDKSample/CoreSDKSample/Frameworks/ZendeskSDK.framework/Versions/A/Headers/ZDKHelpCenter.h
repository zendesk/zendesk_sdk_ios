//
//  ZDKHelpCenter.h
//  ZendeskSDK
//
//  Created by Zendesk on 09/09/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZDKHelpCenter : NSObject


/**
 * Displays the Help Center view on top the view controller
 * that is passed in.
 *
 * @param navController The UINavigationController from which to pressent the request creation view.
 */
+ (void) showHelpCenterWithNavController:(UINavigationController*)navController;


@end
