#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "interf_dec.h"
#import "interf_enc.h"
#import "RCAMRDataConverter.h"
#import "RCChatRoomInfo.h"
#import "RCChatRoomMemberInfo.h"
#import "RCCommandMessage.h"
#import "RCCommandNotificationMessage.h"
#import "RCContactNotificationMessage.h"
#import "RCConversation.h"
#import "RCCSLeaveMessage.h"
#import "RCCSLeaveMessageItem.h"
#import "RCCSPullLeaveMessage.h"
#import "RCCustomerServiceConfig.h"
#import "RCCustomerServiceGroupItem.h"
#import "RCCustomerServiceInfo.h"
#import "RCDiscussion.h"
#import "RCDiscussionNotificationMessage.h"
#import "RCEvaluateItem.h"
#import "RCFileMessage.h"
#import "RCFileUtility.h"
#import "RCGroup.h"
#import "RCGroupNotificationMessage.h"
#import "RCImageMessage.h"
#import "RCIMClient.h"
#import "RCInformationNotificationMessage.h"
#import "RCLocationMessage.h"
#import "RCMentionedInfo.h"
#import "RCMessage.h"
#import "RCMessageContent.h"
#import "RCMessageContentView.h"
#import "RCProfileNotificationMessage.h"
#import "RCPublicServiceCommandMessage.h"
#import "RCPublicServiceMenu.h"
#import "RCPublicServiceMenuItem.h"
#import "RCPublicServiceMultiRichContentMessage.h"
#import "RCPublicServiceProfile.h"
#import "RCPublicServiceRichContentMessage.h"
#import "RCPushProfile.h"
#import "RCReadReceiptInfo.h"
#import "RCRealTimeLocationCommonDefine.h"
#import "RCRealTimeLocationEndMessage.h"
#import "RCRealTimeLocationManager.h"
#import "RCRealTimeLocationStartMessage.h"
#import "RCRecallNotificationMessage.h"
#import "RCRichContentItem.h"
#import "RCRichContentMessage.h"
#import "RCSearchConversationResult.h"
#import "RCStatusDefine.h"
#import "RCStatusMessage.h"
#import "RCTextMessage.h"
#import "RCTSMutableDictionary.h"
#import "RCUnknownMessage.h"
#import "RCUploadImageStatusListener.h"
#import "RCUploadMediaStatusListener.h"
#import "RCUserInfo.h"
#import "RCUserOnlineStatusInfo.h"
#import "RCUserTypingStatus.h"
#import "RCUtilities.h"
#import "RCVoiceMessage.h"
#import "RCWatchKitStatusDelegate.h"
#import "RongIMLib.h"

FOUNDATION_EXPORT double TestPrivateRepoVersionNumber;
FOUNDATION_EXPORT const unsigned char TestPrivateRepoVersionString[];

