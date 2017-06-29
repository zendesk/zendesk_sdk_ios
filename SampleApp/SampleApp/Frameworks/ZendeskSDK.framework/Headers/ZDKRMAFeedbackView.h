/*
 *
 *  ZDKRMAFeedbackView.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 19/02/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "ZDKSpinnerDelegate.h"

@class ZDKRMAConfigObject, ZDKUITextView;

__deprecated_msg("Deprecated as of 1.10.0.1, this will be removed.")

/**
 * Delegate of ZDKRMAFeedbackView. The delegate of a ZDKRMAFeedbackView object
 * must adopt the ZDKRMAFeedbackViewDelegate protocol.
 */
@protocol ZDKRMAFeedbackViewDelegate <NSObject>


/**
 * Tells the delegate that the send feedback action has been selected in the
 * feedback dialog. The delegate should handle sending the feedback to an endpoint.
 */
- (void) sendFeedback:(NSString*)feedback;


/**
 * Tells the delegate that the cancel action has been selected in the
 * feedback dialog. The delegate should handle either returning to previous dialog
 * or dismissing the dialog entirely.
 */
- (void) back;


/**
 * Tells the delegate that the dialog should be closed. The delegate should handle closing 
 * the dialog. 
 *
 */
- (void) closeDialog;


@end


#pragma mark -


typedef NS_ENUM(NSInteger, ZDKRMAFeedbackDialogState) {
    ZDKRMAFeedbackDialogStateEditing = 0,
    ZDKRMAFeedbackDialogStateCancel = 1,
    ZDKRMAFeedbackDialogStateSubmitting = 2,
    ZDKRMAFeedbackDialogStateSuccess = 3,
    ZDKRMAFeedbackDialogStateError = 4
};

__deprecated_msg("Deprecated as of 1.10.0.1, this will be removed.")

/**
 * A ZDKRMAFeedbackView contains a header, a text view and a set of buttons.
 */
@interface ZDKRMAFeedbackView : UIView <UITextViewDelegate> {
    id<ZDKRMAFeedbackViewDelegate> delegate;
}


@property (nonatomic, assign) ZDKRMAFeedbackDialogState feedbackState;


/**
 * A ZDKRMATextView for text entry.
 */
@property (nonatomic, strong) ZDKUITextView *textView;


/**
 * A UIButton calls ZDKRMAFeedbackViewDelegate cancel method.
 */
@property (nonatomic, strong) UIButton *backButton;


/**
 * A UIButton calls ZDKRMAFeedbackViewDelegate sendFeedback method.
 */
@property (nonatomic, strong) UIButton *submitButton;


/**
 * A UIButton dismisses the ZDKRMA dialog.
 */
@property (nonatomic, strong) UIButton *closeButton;


/**
 * A UILabel in the header of the feedback view. This label has only one
 * line and is the main title.
 */
@property (nonatomic, strong) UILabel *titleLabel;


/**
 * A UILabel in the header of the feedback view. This label has three
 * lines and is for any extra details in the header.
 */
@property (nonatomic, strong) UILabel *detailTitleLabel;


/**
 * Displays an image if one has been specified by either successImageName
 */
@property (nonatomic, strong) UIImageView *submissionStatusImageView;

@property (nonatomic, strong) NSString *successImageName;
@property (nonatomic, strong) NSString *errorImageName;

/**
 * Initializes and returns a ZDKRMAFeedbackView with the given ZDKRMAFeedbackViewDelegate.
 *
 * This creates a ZDKRMAFeedbackView with default values for the tables dimensions and appearance.
 *
 * @param del the delegate that implements the ZDKRMADialogViewDelegate protocol.
 *
 * @return An initialized ZDKRMAFeedbackView.
 *
 */
- (instancetype) initWithDelegate:(id<ZDKRMAFeedbackViewDelegate>)del;


/**
 * Displays or hides a spinner over the text view. While the spinner is showing the alpha of the 
 * text view is lowered.
 *
 * @param show If YES the spinner will be shown, if NO the spinner will be hidden.
 */
- (void) showSpinner:(BOOL)show;


/**
 * Transitions the feedback view to a success message state.
 *
 */
- (void) successTransition;


/**
 * Transitions the feedback view to an error message state.
 *
 */
- (void) transitionToError;


/**
 * Transitions the feedback view from an error message state, back to an editing state.
 *
 */
- (void) transitionFromError;


@end

