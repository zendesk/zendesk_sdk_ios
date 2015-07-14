/*
 *
 *  ZDKUIUtil.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 15/10/2014.  
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

@interface ZDKUIUtil : NSObject


/**
 *  Gets the UI_APPEARANCE_SELECTOR value for a class.
 *
 *  @param class    The appearance value will come from this class.
 *  @param selector The appearance selector
 *
 *  @return An appearance value or nil if none have been set.
 */
+ (id) appearanceForClass:(Class)class selector:(SEL)selector;


/**
 *  Gets the UI_APPEARANCE_SELECTOR value for a class returning a default value if none have been set.
 *
 *  @param class        The appearance value will come from this class.
 *  @param selector     The appearance selector
 *  @param defaultValue The default value to use if no appearance value has been set.
 *
 *  @return An appearance value.
 */
+ (id) appearanceForClass:(Class)class selector:(SEL)selector defaultValue:(id)defaultValue;


/**
 *  Gets the UI_APPEARANCE_SELECTOR value for a view.
 *
 *  @param view     The appearance value will come from this view.
 *  @param selector The appearance selector.
 *
 *  @return The appearance value or nil if none has been set.
 */
+ (id) appearanceForView:(UIView*)view selector:(SEL)selector;


/**
 *  Gets the UI_APPEARANCE_SELECTOR value for a view returning a default if none has been set.
 *
 *  @param view         The appearance value will come from this view.
 *  @param selector     The appearance selector.
 *  @param defaultValue A default value to use if no appearance value has been set.
 *
 *  @return An appearance value.
 */
+ (id) appearanceForView:(UIView*)view selector:(SEL)selector defaultValue:(id)defaultValue;


/**
 *  Checks to see if the majorVersionNumber is less than the current device version
 *
 *  @param majorVersionNumber is a single integer, eg: 7
 *
 *  @return YES if the current device number is less than majorVersionNumber.
 */
+ (BOOL) isOlderVersion:(NSNumber *) majorVersionNumber;


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


/**
 * Convenience method for creating UIButton.
 *
 * @param frame is the initial frame.
 * @param title is the title string.
 * @return A new button.
 */
+ (UIButton*) buildButtonWithFrame:(CGRect)frame andTitle:(NSString*)title;


/**
 *  Returns current interface orientation. If orientation is unknown presume portrait
 *
 *  @return Current interface orientation
 */
+ (UIInterfaceOrientation) currentInterfaceOrientation;


/**
 *  <#Description#>
 *
 *  @param size  <#size description#>
 *  @param width <#width description#>
 *
 *  @return <#return value description#>
 */
+ (CGFloat) scaledHeightForSize:(CGSize)size constrainedByWidth:(CGFloat)width;


/**
 *  <#Description#>
 *
 *  @return <#return value description#>
 */
+ (BOOL) isPad;


/**
 *  <#Description#>
 *
 *  @return <#return value description#>
 */
+ (BOOL) isLandscape;


/*
 *  Physically transform an image to match its imageRotation property.
 *
 *  @param image Image to rotate.
 *
 *  @return Correctly rotated image.
 */
+ (UIImage *)fixOrientationOfImage:(UIImage*)image;


@end

CG_INLINE CGRect
CGRectMakeCenteredInScreen(CGFloat width, CGFloat height)
{
    CGRect screen = [UIScreen mainScreen].bounds;
    
    UIInterfaceOrientation orientation = [UIApplication sharedApplication].statusBarOrientation;
    
    CGRect rect;
    
    if (orientation == UIInterfaceOrientationLandscapeLeft ||
        orientation == UIInterfaceOrientationLandscapeRight) {
        if([ZDKUIUtil isOlderVersion:@8])
        {
            rect = CGRectMake(CGRectGetMidY(screen) - (width * 0.5f),
                              CGRectGetMidX(screen) - (height * 0.5f), width, height);
        }else{
            rect = CGRectMake(CGRectGetMidX(screen) - (width * 0.5f),
                              CGRectGetMidY(screen) - (height * 0.5f), width, height);
        }
        
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


/**
 * Helper for device orientation.
 */
CG_INLINE BOOL
ZDKUIIsLandscape()
{
    UIInterfaceOrientation orientation = [UIApplication sharedApplication].statusBarOrientation;
    return UIInterfaceOrientationIsLandscape(orientation);
}


/**
 * Returns the full screen frame with no attempt to account for the status bar.
 */
CG_INLINE CGRect
ZDKUIScreenFrame()
{
    CGSize screenSize = [UIScreen mainScreen].bounds.size;
    
    CGFloat width = screenSize.width;
    CGFloat height = screenSize.height;
    
    if (ZDKUIIsLandscape() && width < height) {
        
        width = height;
        height = screenSize.width;
    }
    
    return CGRectMake(0, 0, width, height);
}


/**
 * Get the origin of the supplied view in the window.
 */
CG_INLINE CGPoint
ZDKUIOriginInWindow(UIView *view)
{
    UIView *superView = view;
    do {
        superView = superView.superview;
    } while (superView.superview);
    CGPoint point = [view convertPoint:view.bounds.origin toView:superView];
    if ([ZDKUIUtil isNewerVersion:@(7)]) {
        return point;
    }
    CGRect screenBounds = [UIScreen mainScreen].bounds;
    switch ([[UIApplication sharedApplication] statusBarOrientation]) {
        case UIInterfaceOrientationPortraitUpsideDown: {
            return CGPointMake(screenBounds.size.width - point.x, screenBounds.size.height - point.y);
        }
        case UIInterfaceOrientationLandscapeLeft: {
            return CGPointMake(screenBounds.size.height - point.y, point.x);
        }
        case UIInterfaceOrientationLandscapeRight: {
            return CGPointMake(point.y, screenBounds.size.width - point.x);
        }
        default: {
            return point;
        }
    }
}

