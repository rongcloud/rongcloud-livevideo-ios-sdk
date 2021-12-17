//
//  RCLiveVideoCode.h
//  RCE
//
//  Created by 叶孤城 on 2021/9/3.
//

#import <Foundation/Foundation.h>

#ifndef RCLiveVideoCode_h
#define RCLiveVideoCode_h

typedef NS_ENUM(NSInteger, RCLiveVideoCode) {
    /// 操作成功
    RCLiveVideoSuccess = 80000,
    
    /// 加入房间失败
    RCLiveVideoRoomJoinError = 80101,
    
    /// 离开房间失败
    RCLiveVideoRoomLeaveError = 80102,
    
    /// 没有加入房间
    RCLiveVideoRoomStateError = 80103,
    
    /// 发布直播流失败
    RCLiveVideoStreamPublishError = 80201,
    
    /// 订阅分流失败
    RCLiveVideoStreamSubscribeError = 80202,
    
    /// CDN订阅流失败
    RCLiveVideoCDNStreamSubscribeError = 80203,
    
    /// CDN设置流参数失败
    RCLiveVideoCDNStreamConfigError = 80204,
    
    
    /// 获取房间信息失败
    RCLiveVideoRoomInfoGetError = 80301,
    /// 更新房间信息失败
    RCLiveVideoRoomInfoSetError = 80302,
    
    /// 加入连麦失败
    RCLiveVideoLinkMicJoinError = 80401,
    /// 连麦状态错误
    RCLiveVideoLinkMicStateError = 80403,
    
    /// 申请连麦失败
    RCLiveVideoLinkMicRequestError = 80411,
    RCLiveVideoLinkMicRequestFull = 80412,
    RCLiveVideoLinkMicRequestConnecting = 80413,
    RCLiveVideoLinkMicRequestAcceptError = 80414,
    RCLiveVideoLinkMicRequestRejectError = 80415,
    
    /// 麦位
    RCLiveVideoSeatInvalid = 80501,
    RCLiveVideoSeatIsFull = 80502,
    RCLiveVideoSeatIsLock = 80503,
    RCLiveVideoSeatUserExist = 80504,
    
    /// 设置了相同的连麦类型
    RCLiveVideoMixSame = 80601,
    
    /// 信息发送失败
    RCLiveVideoMessageSendError = 81001,
    
    /// 权限错误
    RCLiveVideoPermissionError = 82001,
};

#endif /* RCLiveVideoCode_h */
