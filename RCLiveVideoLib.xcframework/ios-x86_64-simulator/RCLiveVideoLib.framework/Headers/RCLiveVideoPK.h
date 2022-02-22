//
//  RCLiveVideoPK.h
//  Alamofire
//
//  Created by shaoshuai on 2021/12/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RCLiveVideoPK : NSObject

@property (nonatomic, copy, nonnull) NSString *inviterUserId;
@property (nonatomic, copy, nonnull) NSString *inviterRoomId;
@property (nonatomic, copy, nonnull) NSString *inviteeUserId;
@property (nonatomic, copy, nonnull) NSString *inviteeRoomId;

- (instancetype)initWithInviterId:(NSString *)inviterUserId
                    inviterRoomId:(NSString *)inviterRoomId
                        inviteeId:(NSString *)inviteeUserId
                    inviteeRoomId:(NSString *)inviteeRoomId;

/// 类方法，根据 JSON 生成一个 RCLiveVideoPK 实例
/// @param JSON RCLiveVideoPK 的 JSON
+ (RCLiveVideoPK *)PKWithJSON:(NSString *)JSON;

/// 自动生成该类对应的 JSON 字符串
- (NSString *)JSON;

/// 当前房间信息
- (NSString *)roomId;
- (NSString *)roomUserId;

/// 其它房间信息
- (NSString *)otherRoomId;
- (NSString *)otherRoomUserId;

@end

NS_ASSUME_NONNULL_END
