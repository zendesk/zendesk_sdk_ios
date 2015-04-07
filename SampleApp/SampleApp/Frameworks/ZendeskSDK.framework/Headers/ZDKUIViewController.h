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


struct ZDKLayoutGuide {
    BOOL layoutTopGuide;
    BOOL layoutBottomGuide;
};

typedef struct ZDKLayoutGuide ZDKLayoutGuide;

extern ZDKLayoutGuide const ZDKLayoutRespectAll;
extern ZDKLayoutGuide const ZDKLayoutRespectNone;
extern ZDKLayoutGuide const ZDKLayoutRespectTop;
extern ZDKLayoutGuide const ZDKLayoutRespectBottom;


/**
 * Base view controller class used by ZD components containing frequently used methods.
 */
@interface ZDKUIViewController : UIViewController {

    UIViewAnimationOptions _animationCurve;
    NSTimeInterval _animationDuration;
    CGFloat _keyboardHeight;
    CGFloat _toastHeight;
}


/**
 * Should the view controller respect topLayoutGuide and bottomLayoutGuide introduced in iOS7.
 */
@property (nonatomic, assign) ZDKLayoutGuide layoutGuide;


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
 *  Called when the the keyboard has been shown.
 *
 *  @param aNotification the notifiction
 */
- (void) keyboardDidShow:(NSNotification *)aNotification;


/**
 * Called when the keyboard is about to be hidden, invoke [super keyboardWillBeShown:] to
 * set the currentKeyboardHeight variable with the3 height of the keyboard.
 * @param aNotification the notification
 */
- (void) keyboardWillBeHidden:(NSNotification*)aNotification;


/**
 *  Callked when the keyboard has hidden.
 *
 *  @param aNotification the notification
 */
- (void) keyboardDidHide:(NSNotification *)aNotification;

/**
 *  Updates values associated with the keyboard displaying/dismissing
 *
 *  @param userInfo the user info dictionary from keyboard notifications.
 */
- (void) updateAnimationValuesFromUserInfo:(NSDictionary*)userInfo;


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
 *  Gets the active SDK view controller.
 *
 *  @since 1.2.0.1
 *
 *  @return The current SDK view controller.
 */
+ (ZDKUIViewController *) activeController;


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

