//
//  RCLiveVideoDefine.h
//  RCE
//
//  Created by shaoshuai on 2021/9/27.
//

#import <Foundation/Foundation.h>

#import "RCLiveVideoCode.h"

#ifndef RCLiveVideoDefine_h
#define RCLiveVideoDefine_h

typedef void(^RCLVResult)(RCLiveVideoCode code);

typedef NS_ENUM(NSInteger, RCLiveVideoMixType) {
    /// 默认模式
    RCLiveVideoMixTypeDefault = 0,
    /// 小窗模式
    RCLiveVideoMixTypeOneToOne,
    RCLiveVideoMixTypeOneToSix,
    /// 格子模式
    RCLiveVideoMixTypeGridTwo,
    RCLiveVideoMixTypeGridThree,
    RCLiveVideoMixTypeGridFour,
    RCLiveVideoMixTypeGridSeven,
    RCLiveVideoMixTypeGridNine,
    /// 自定义模式
    RCLiveVideoMixTypeCustom,
};

typedef NS_ENUM(NSInteger, RCLiveVideoMixSize) {
    RCLiveVideoMixSize640x360,
    RCLiveVideoMixSize1280x720,
    RCLiveVideoMixSize1920x1080,
};

typedef NS_ENUM(NSInteger, RCLiveVideoFinishReason) {
    RCLiveVideoFinishReasonUnknown,
    RCLiveVideoFinishReasonLeave,
    RCLiveVideoFinishReasonKick,
    RCLiveVideoFinishReasonMix,
};

typedef NS_ENUM(NSInteger, RCLiveVideoPKResponse) {
    RCLiveVideoPKResponseAccept,
    RCLiveVideoPKResponseReject,
    RCLiveVideoPKResponseIgnore,
    RCLiveVideoPKResponseBusy,
};

#endif /* RCLiveVideoDefine_h */
