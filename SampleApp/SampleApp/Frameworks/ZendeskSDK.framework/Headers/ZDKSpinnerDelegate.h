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
 * Start the spinner animating.
 */
- (void) startAnimating;


/**
 * Stop the spinner animating.
 */
- (void) stopAnimating;


/**
 * Is the view hidden?
 * @return true if hidden
 */
- (BOOL) hidden;


/**
 * Set the views hidden state.
 * @param isHidden set as true to hide, if setting to hidden the animation wil be stopped
 */
- (void) setHidden:(BOOL)isHidden;


/**
 * Get the current frame of the view.
 @ @return the view frame
 */
- (CGRect) frame;

/**
 * Get the current center of the view
 @ @return the view center
 */
- (CGPoint) center;

/**
 * Set the center of the view
 * @param center to be set
 */
- (void) setCenter:(CGPoint)center;

/**
 * Set the frame of the view.
 * @param frame the frame to set
 */
- (void) setFrame:(CGRect)frame;


@end


/**
 * Spinner creation block.
 * @param frame rect for the spinner
 */
typedef id<ZDKSpinnerDelegate> (^ZDUISpinner) (CGRect frame);

