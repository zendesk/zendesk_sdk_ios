//
//  ZDKHelpCenterTableDelegate.h
//  ZendeskSDK
//
//  Created by Zendesk on 15/09/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZDKHelpCenterTableDelegate : NSObject <UITableViewDelegate>


/**
 * Block touches when there is no network connectivity. 
 */
@property (nonatomic, assign, readonly) BOOL blockTouches;

@end


@interface ZDKHelpCenterSearchResultTableDelegate : ZDKHelpCenterTableDelegate

@end
