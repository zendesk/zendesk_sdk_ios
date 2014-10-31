//
//  ZDRateMyAppDemoViewController.h
//  ZDRateMyAppSample
//
//  Created by Zendesk on 27/03/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <UIKit/UIKit.h>


/**
 * Sample view controller.
 */
@interface ZDRateMyAppDemoViewController : UIViewController


- (CGRect) buttonRect;


- (UIButton*)    button:(NSString*)title
accessibilityIdentifier:(NSString*)identifier
               selector:(SEL)selector
                  frame:(CGRect)buttonRect;


@end

