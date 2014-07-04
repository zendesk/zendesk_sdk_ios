//
//  ZDSpinnerDelegate.h
//  ZDUI
//
//  Created by Zendesk on 30/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <Foundation/Foundation.h>


/**
 * Spinner control delegate.
 */
@protocol ZDSpinnerDelegate <NSObject>


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
 * Set the frame of the view.
 * @param frame the frame to set
 */
- (void) setFrame:(CGRect)frame;


@end


/**
 * Spinner creation block.
 * @param the rect for the spinner
 */
typedef id<ZDSpinnerDelegate> (^ZDUISpinner) (CGRect frame);

