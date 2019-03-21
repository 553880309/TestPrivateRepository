//
//  WUBAPushMessage.h
//  WUBAPush
//
//  Created by whisper on 16/4/4.
//  Copyright © 2016年 58ganji. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef enum : NSUInteger {
    WUBAPushMessageTypeNomal,
    WUBAPushMessageTypeVoip
} WUBAPushMessageType;
@interface WUBAPushMessage : NSObject
@property(nonatomic,assign)WUBAPushMessageType type;
@property(nonatomic,copy)NSString *messageID;
@property(nonatomic,copy)NSString *messageContent;
@property(nonatomic,copy)NSString *messageType;
@property(nonatomic,copy)NSString * alert;
@property(nonatomic,assign)NSInteger badge;
@property(nonatomic,copy)NSString * sound;
@property(nonatomic,strong)NSDictionary *messageInfos;
//@private
@end
