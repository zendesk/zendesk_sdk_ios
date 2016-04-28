/*
 *
 *  ZDKSpinnerDelegate.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 30/04/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */


#import <Foundation/Foundation.h>


/**
 * Spinner control delegate.
 */
@protocol ZDKSpinnerDelegate <NSObject>


/**
 *  Frame of spinner.
 */
@property (nonatomic) CGRect frame;


/**
 *  Is the spinner hidden? YES or NO.
 */
@property (nonatomic) BOOL hidden;


/**
 *  The center of the view.
 */
@property (nonatomic) CGPoint center;


/**
 * Start the spinner animating.
 */
- (void) startAnimating;


/**
 * Stop the spinner animating.
 */
- (void) stopAnimating;


@end


/**
 * Spinner creation block.
 * @param frame rect for the spinner
 */
typedef id<ZDKSpinnerDelegate> (^ZDUISpinner) (CGRect frame);

