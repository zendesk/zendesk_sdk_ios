//
//  ZDUIStyle.h
//  ZDUI
//
//  Created by Zendesk on 28/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZDSpinnerDelegate.h"


CG_INLINE CGRect
CGRectMakeCenteredInScreen(CGFloat width, CGFloat height)
{
    CGRect screen = [[UIScreen mainScreen] bounds];
   
    UIInterfaceOrientation orientation = [UIApplication sharedApplication].statusBarOrientation;

    CGRect rect;
    
    if (orientation == UIInterfaceOrientationLandscapeLeft ||
        orientation == UIInterfaceOrientationLandscapeRight) {
        rect = CGRectMake(CGRectGetMidY(screen) - (width * 0.5),
                          CGRectGetMidX(screen) - (height * 0.5), width, height);
        
    } else {
        rect = CGRectMake(CGRectGetMidX(screen) - (width * 0.5),
                          CGRectGetMidY(screen) - (height * 0.5), width, height);
    }
    return rect;
}


CG_INLINE CGRect
CGMakeCenteredRectInRect(CGFloat width, CGFloat height, CGRect rect)
{
    return CGRectMake(CGRectGetMidX(rect) - (width * 0.5),
                      CGRectGetMidY(rect) - (height * 0.5), width, height);
}


CG_INLINE CGRect
CGMakeCenteredRectOnXInRect(CGFloat width, CGFloat height, CGFloat y, CGRect frame)
{
    CGRect rect;
    rect = CGRectMake(CGRectGetMidX(frame) - (width * 0.5), y, width, height);
    return rect;
}


CG_INLINE CGRect
CGCenterRectInRect(CGRect rect, CGRect inRect)
{
    return CGRectMake((CGRectGetHeight(inRect) - CGRectGetMinX(rect)) * 0.5,
                      (CGRectGetHeight(inRect) - CGRectGetHeight(rect)) * 0.5,
                      CGRectGetWidth(rect),
                      CGRectGetHeight(rect));
}


#pragma mark - ZDUIStyle

/**
 * TODO docs
 */
@interface ZDUIStyle : NSObject


/**
 * TODO docs
 * @return
 */
+ (CGFloat) separatorHeightForScreenScale;


@end
