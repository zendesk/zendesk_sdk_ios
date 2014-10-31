//
//  ZDSecondViewController.m
//
//  Created by Zendesk on 19/02/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import "ZDSecondViewController.h"
#import <ZendeskSDK/ZendeskSDK.h>


@implementation ZDSecondViewController


- (void) viewDidLoad
{
    [super viewDidLoad];
    
    self.view.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;
    self.view.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:[self button:@"Push a view"
               accessibilityIdentifier:@"zdrma.sampleapp.push-view-button"
                              selector:@selector(pushView)
                                 frame:[self buttonRect]]];
}


- (void) viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Show Rate My App dialog if it is due and the user remains on this screen for 2 seconds
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    [ZDKRMA showInView:self.view];
}


- (void) pushView
{
    UIViewController *vc = [UIViewController new];
    vc.view.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;
    vc.title = self.title;
    [self.navigationController pushViewController:vc animated:YES];
}


@end

