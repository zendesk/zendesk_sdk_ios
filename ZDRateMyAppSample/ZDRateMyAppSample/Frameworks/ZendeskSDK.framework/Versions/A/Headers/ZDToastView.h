//
//  ZDToastView.h
//  ZDToast
//
//  Created by Zendesk on 12/05/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "ZDToastStyle.h"


/**
 * The view for presenting default toast messages.
 * @since 0.1
 */
@interface ZDToastView : UIView {

    /**
     * The actual toast content.
    * @since 0.1
     */
    UIView *toast;

    /**
     * Single pixel lower border.
     * @since 0.1
     */
    UIView *lowerBorder;

    /**
     * The message itself.
     * @since 0.1
     */
    UILabel *text;

    /**
     * Animation time.
     * @since 0.1
     */
    NSTimeInterval animationTime;

    /**
     * Presentation time.
     * @since 0.1
     */
    NSTimeInterval durationInSeconds;

}

/**
 * Timestamp for the point at which the toast has finished animating in.
 * @since 0.1
 */
@property (strong) NSDate *timePresented;


/**
 * Initialise and animate in a new toast.
 * @param view the view in which the toast is to be presented
 * @param y the y for the start of the toast frame
 * @param msg the text to be presented
 * @param type the ZDToastTypeEnum type of the toast
 * @param durationInSeconds the duration for which the toast should be fully visible
 * @param animationTime the time the toast should spend per animation in/out
 * @since 0.1
 */
- (id) initInView:(UIView*)view
              atY:(CGFloat)y
      withMessage:(NSString*)msg
          andType:(ZDToastTypeEnum)type
         duration:(NSTimeInterval)durationInSeconds
    animationTime:(NSTimeInterval)animationTime;


@end

