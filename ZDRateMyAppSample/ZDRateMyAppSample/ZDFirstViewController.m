//
//  ZDFirstViewController.m
//  ZDRateMyAppSample
//
//  Created by Zendesk on 27/03/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import "ZDFirstViewController.h"
#import "ZDSecondViewController.h"
#import <ZendeskSDK/ZDRMA.h>


@interface ZDFirstViewController ()

@property (nonatomic, retain) UIView *primaryView;
@property (nonatomic, retain) UIView *secondaryView;

@end


@implementation ZDFirstViewController


@synthesize primaryView, secondaryView;


- (void) viewDidLoad
{
    [super viewDidLoad];

    CGRect buttonRect = [self buttonRect];

    // primary view which is presented on top
    primaryView = [[UIView alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    primaryView.backgroundColor = [UIColor whiteColor];
    primaryView.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;
    [self.view addSubview:primaryView];

    [primaryView addSubview:[self button:@"Push a view"
                 accessibilityIdentifier:@"zdrma.sampleapp.push-view-button"
                                selector:@selector(toggleView)
                                   frame:buttonRect]];

    [primaryView addSubview:[self button:@"Push a view controller"
                 accessibilityIdentifier:@"zdrma.sampleapp.push-viewcontroller-button"
                                selector:@selector(pushViewController)
                                   frame:CGRectOffset(buttonRect, 0, buttonRect.size.height * 3)]];

    // secondary view to be placed moved into focus on button press
    secondaryView = [[UIView alloc] initWithFrame:primaryView.frame];
    secondaryView.backgroundColor = primaryView.backgroundColor;
    secondaryView.layer.shadowRadius = 5.0f;
    secondaryView.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;
    [self.view insertSubview:secondaryView belowSubview:primaryView];

    [secondaryView addSubview:[self button:@"Pop this view"
                   accessibilityIdentifier:@"zdrma.sampleapp.pop-view-button"
                                  selector:@selector(toggleView)
                                     frame:buttonRect]];
}


- (CGRect) buttonRect
{
    CGRect screen = [[UIScreen mainScreen] bounds];
    CGFloat width = 180.0f, height = 30.0f;
    return CGRectMake(CGRectGetMidX(screen) - (width / 2),
                      CGRectGetMidY(screen) - (height / 2),
                      width, height);
}


- (UIButton*)    button:(NSString*)title
accessibilityIdentifier:(NSString*)identifier
               selector:(SEL)selector
                  frame:(CGRect)buttonRect
{
    UIButton *button = [self buildButtonWithFrame:buttonRect andTitle:title];
    button.accessibilityIdentifier = identifier;
    [button addTarget:self action:selector forControlEvents:UIControlEventTouchUpInside];
    button.autoresizingMask = UIViewAutoresizingFlexibleBottomMargin |
                                UIViewAutoresizingFlexibleTopMargin |
                                UIViewAutoresizingFlexibleLeftMargin |
                                UIViewAutoresizingFlexibleRightMargin;
    return button;
}


- (UIButton*) buildButtonWithFrame:(CGRect)frame andTitle:(NSString*)title
{
    UIButton *button = [[UIButton alloc] initWithFrame:frame];
    button.backgroundColor = [UIColor colorWithWhite:0.9450f alpha:1.0f];
    button.layer.borderColor = [UIColor colorWithWhite:0.8470f alpha:1.0f].CGColor;
    button.layer.borderWidth = 1.0f;
    button.layer.cornerRadius = 4.0f;
    button.titleLabel.font = [UIFont systemFontOfSize:14];
    [button setTitleColor:[UIColor colorWithWhite:0.2627f alpha:1.0f] forState:UIControlStateNormal];
    [button setTitleColor:[UIColor colorWithWhite:0.2627f alpha:0.3f] forState:UIControlStateHighlighted];
    [button setTitleColor:[UIColor colorWithWhite:0.2627f alpha:0.3f] forState:UIControlStateDisabled];
    [button setTitle:title forState:UIControlStateNormal];
    [button setTitle:title forState:UIControlStateHighlighted];
    button.titleLabel.textAlignment = NSTextAlignmentCenter;
    return button;
}


- (void) toggleView
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Show Rate My App dialog if it is due and this view remains on the screen for 2 seconds
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    [ZDRMA showInView:secondaryView];

    UIView *one = [[self.view subviews] objectAtIndex:0];
    UIView *two = [[self.view subviews] objectAtIndex:1];

    one.hidden = NO;
    two.hidden = YES;
    [self.view exchangeSubviewAtIndex:0 withSubviewAtIndex:1];
}


- (void) pushViewController
{
    ZDSecondViewController *vc = [ZDSecondViewController new];
    vc.title = self.title;
    [self.navigationController pushViewController:vc animated:YES];
}


@end

