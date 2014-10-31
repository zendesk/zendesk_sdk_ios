//
//  ZDKUIUtil.h
//  ZendeskSDK
//
//  Created by Zendesk on 15/10/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>


CG_INLINE CGRect
CGRectMakeCenteredInScreen(CGFloat width, CGFloat height)
{
    CGRect screen = [[UIScreen mainScreen] bounds];
    
    UIInterfaceOrientation orientation = [UIApplication sharedApplication].statusBarOrientation;
    
    CGRect rect;
    
    if (orientation == UIInterfaceOrientationLandscapeLeft ||
        orientation == UIInterfaceOrientationLandscapeRight) {
        rect = CGRectMake(CGRectGetMidY(screen) - (width * 0.5f),
                          CGRectGetMidX(screen) - (height * 0.5f), width, height);
        
    } else {
        rect = CGRectMake(CGRectGetMidX(screen) - (width * 0.5f),
                          CGRectGetMidY(screen) - (height * 0.5f), width, height);
    }
    return rect;
}


CG_INLINE CGRect
CGMakeCenteredRectInRect(CGFloat width, CGFloat height, CGRect rect)
{
    return CGRectMake(CGRectGetMidX(rect) - (width * 0.5f),
                      CGRectGetMidY(rect) - (height * 0.5f), width, height);
}


CG_INLINE CGRect
CGMakeCenteredRectOnXInRect(CGFloat width, CGFloat height, CGFloat y, CGRect frame)
{
    CGRect rect;
    rect = CGRectMake(CGRectGetMidX(frame) - (width * 0.5f), y, width, height);
    return rect;
}


CG_INLINE CGRect
CGCenterRectInRect(CGRect rect, CGRect inRect)
{
    return CGRectMake((CGRectGetHeight(inRect) - CGRectGetMinX(rect)) * 0.5f,
                      (CGRectGetHeight(inRect) - CGRectGetHeight(rect)) * 0.5f,
                      CGRectGetWidth(rect),
                      CGRectGetHeight(rect));
}


@interface ZDKUIUtil : NSObject


/**
 * isNewVersion checks to see if the majorVersionNumber is greater than the current device version
 * @param majorVersionNumber is a single integer, eg: 7
 */
+ (BOOL) isNewerVersion:(NSNumber *) majorVersionNumber;


/**
 * isSameVersion checks to see if the majorVersionNumber is the same as the current device version
 * @param majorVersionNumber is a single integer, eg: 7
 */
+ (BOOL) isSameVersion:(NSNumber *) majorVersionNumber;


/**
 * The height of a seporator for retina and none retina screens.
 *
 * @return Height of seporator.
 */
+ (CGFloat) separatorHeightForScreenScale;


@end
