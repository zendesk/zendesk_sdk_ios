/*
 *
 *  ZDKUIViewController.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 29/04/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */


#import <UIKit/UIKit.h>

@class ZDKReachability, ZDKToastView;


/**
 * Helper for device orientation.
 */
CG_INLINE BOOL
ZDKUIIsLandscape()
{
    UIInterfaceOrientation orientation = [[UIApplication sharedApplication] statusBarOrientation];
    return UIInterfaceOrientationIsLandscape(orientation);
}


/**
 * Base view controller class used by ZD components containing frequently used methods.
 */
@interface ZDKUIViewController : UIViewController {
    
    CGFloat _keyboardHeight;
    CGFloat _toastHeight;
}


/** 
 * Requires existence of navigation controller in parent view controller.
 */
@property (nonatomic, assign) BOOL requiresNavBar;


/**
 * The content view for this view controller. Any subviews should be added this.
 *
 * All subclasses should use this view as a base for their view hierarchy.
 */
@property (nonatomic, strong) UIView *contentView;


/**
 * A toast for notifying users about network connectivity issues and request errors.
 */
@property (nonatomic, strong) ZDKToastView *toastView;


/**
 * Used to determin network reachability.
 */
@property (nonatomic, strong, readonly) ZDKReachability *reachable;


#pragma mark keyboard event handling


/**
 * Register the view controler to be notified of keyboard show/hide events.
 * Override keyboardWillBeShown: and keyboardWillBeHidden: to handle the events
 */
- (void) registerForKeyboardNotifications;


/**
 * Called when the keyboard is about to be shown, invoke [super keyboardWillBeShown:] to
 * set the currentKeyboardHeight variable with the height of the keyboard.
 * @param aNotification the notification
 */
- (void) keyboardWillBeShown:(NSNotification*)aNotification;


/**
 * Called when the keyboard is about to be hidden, invoke [super keyboardWillBeShown:] to
 * set the currentKeyboardHeight variable with the3 height of the keyboard.
 * @param aNotification the notification
 */
- (void) keyboardWillBeHidden:(NSNotification*)aNotification;


#pragma mark Layout 


/**
 * Layout the the view with restpect to any ZDKToastView that may be showing. 
 */
- (void) layoutContent;


#pragma mark offsets


/**
 * Top offset for IOS7+ transparent status and nav bars
 */
- (CGFloat) topViewOffset;


/**
 * Bottom offset for IOS7+ transparent toolbars
 */
- (CGFloat) bottomViewOffset;


#pragma mark - view controller utils


/**
 * Get the top view controller from thw app window.
 *
 * @return the top view controller for the app.
 */
+ (UIViewController*) topViewController;


/**
 * Get the top view controller from root controller provided.
 *
 * @param rootViewController root view controller from which to start looking
 * @return the top view controller
 */
+ (UIViewController*) topViewControllerWithRootViewController:(UIViewController*)rootViewController;


/**
 * Present the view controller. If the current top view controller 
 * is or has a navigation controller then the view will be pushed on 
 * to that controller, otherwise a new navigation controller will be
 * pushed (vertical transition).
 */
+ (void) presentViewController:(UIViewController*)viewController requiresNavController:(BOOL)requiresNav;


@end

