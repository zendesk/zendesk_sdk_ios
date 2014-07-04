//
//  ZDUI.h
//  ZDUI
//
//  Created by Zendesk on 22/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "ZDUIStyle.h"
#import "ZDUITextView.h"
#import "ZDUIUIViewController.h"
#import "ZDUIActivityView.h"


#define ZD_ISIOS7  ([[[UIDevice currentDevice] systemVersion] compare:@"7" options:NSNumericSearch] != NSOrderedAscending)


/**
 * Top level of the ZDUI project, imports this for references to all headers in the project.
 */
@interface ZDUI : NSObject


@end
