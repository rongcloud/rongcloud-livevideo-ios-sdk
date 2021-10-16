//
//  RCLiveVideoErrorCode.h
//  RCE
//
//  Created by 叶孤城 on 2021/9/3.
//

#ifndef RCLiveVideoErrorCode_h
#define RCLiveVideoErrorCode_h

typedef NS_ENUM(NSInteger, RCLiveVideoErrorCode) {
    /// 操作成功
    RCLiveVideoSuccess = 80000,
    
    /// 加入聊天室房间失败
    RCLiveVideoJoinChatRoomFailed,
    /// 加入RTC房间失败
    RCLiveVideoJoinRTCRoomFailed,
    
    /// 离开房间失败
    RCLiveVideoLeaveRoomFailed,
    
    /// 没有加入房间或房间状态异常
    RCLiveVideoNotJoinRoom,
    
    /// 发布流失败
    RCLiveVideoPublishStreamFailed,
    /// 订阅流失败
    RCLiveVideoSubscribeStreamFailed,
    
    /// 获取房间信息失败
    RCLiveVideoGetRoomInfoFailed,
    /// 更新房间信息失败
    RCLiveVideoUpdateRoomInfoFailed,
    
    /// 加入直播失败
    RCLiveVideoJoinLiveVideoFailed,
    /// 离开直播失败
    RCLiveVideoLeaveLiveVideoFailed,
    
    /// 申请直播失败
    RCLiveVideoReqeustFailed,
    RCLiveVideoReqeustIsFull,
    RCLiveVideoAcceptReqeustFailed,
    RCLiveVideoRejectReqeustFailed,
    /// 邀请直播失败
    RCLiveVideoInviteFailed,
    RCLiveVideoInvitationIsFull,
    RCLiveVideoAcceptInvitationFailed,
    RCLiveVideoRejectInvitationFailed,
    
    RCLiveVideoLiveVideoIsFull,
    
    /// 信息发送失败
    RCLiveVideoSendMessageFailed,
};


#endif /* RCLiveVideoErrorCode_h */
