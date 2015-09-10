//
//  ZDRateMyAppDemoViewController.m
//  SampleApp
//
//  Created by Zendesk on 27/03/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import "ZDRateMyAppDemoViewController.h"
#import <ZendeskSDK/ZendeskSDK.h>


@implementation ZDRateMyAppDemoViewController


- (void) viewDidLoad
{
    [super viewDidLoad];

    self.title = @"Rate My App";

    self.view.backgroundColor = [UIColor whiteColor];

    // Shows the dialog if the configuration permits it
    [ZDKRMA showInView:self.view];

}
@end

