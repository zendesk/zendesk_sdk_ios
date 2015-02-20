/*
 *
 *  ZDKRMAFeedbackView.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 19/02/2014.  
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
#import "ZDKSpinnerDelegate.h"

@class ZDKRMAConfigObject, ZDKUITextView;


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
 * or dissmissing the dialog entirely.
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


/**
 * A ZDKRMAFeedbackView contains a header, a text view and a set of buttons.
 */
@interface ZDKRMAFeedbackView : UIView <UITextViewDelegate> {
    id<ZDKRMAFeedbackViewDelegate> delegate;
}


@property (nonatomic) ZDKRMAFeedbackDialogState feedbackState;


/**
 * A ZDKRMATextView for text entry.
 */
@property (nonatomic, retain) ZDKUITextView *textView;


/**
 * A UIButton calls ZDKRMAFeedbackViewDelegate cancel method.
 */
@property (nonatomic, retain) UIButton *backButton;


/**
 * A UIButton calls ZDKRMAFeedbackViewDelegate sendFeedback method.
 */
@property (nonatomic, retain) UIButton *submitButton;


/**
 * A UIButton dismisses the ZDKRMA dialog.
 */
@property (nonatomic, retain) UIButton *closeButton;


/**
 * A UILabel in the header of the feedback view. This label has only one
 * line and is the main title.
 */
@property (nonatomic, retain) UILabel *titleLabel;


/**
 * A UILabel in the header of the feedback view. This label has three
 * lines and is for any extra details in the header.
 */
@property (nonatomic, retain) UILabel *detailTitleLabel;


/**
 * Displays an image if one has been specified by either successImageName
 */
@property (nonatomic, retain) UIImageView *submissionStatusImageView;


@property (nonatomic, strong) UIColor *buttonColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *buttonSelectedColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *buttonBackgroundColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *separatorLineColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *headerFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *subheaderFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *textEntryFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIFont *buttonFont UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) id<ZDKSpinnerDelegate> spinner UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *viewBackgroundColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *headerColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *subHeaderColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *textEntryColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *textEntryBackgroundColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *placeHolderColor UI_APPEARANCE_SELECTOR;

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

