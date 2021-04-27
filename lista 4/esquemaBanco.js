// UidX -> Representa id de um usuario
// PidX -> Representa id de um pet
// UidX_UidY -> Representa id de um chat entre oo user x com  o user Y
// MidX -> Representa o id de uma mensagem

const esquema = {
  users: {
    Uid1: {...},
    Uid2: {...},
    Uid3: {
      name: 'blabla',
      phone: 'blabla',
      photos: [
        'url',
        'url',
        'url',
      ],
      pets: [
        Pid1,
        Pid2,
        Pid3,
      ],
      chats: [
        Uid3_Uid2,
        Uid3_Uid4,
        Uid3_Uid1,
      ]
    },
  },

  pets: {
    Pid1: {...},
    Pid2: {...},
    Pid3: {
      name: 'blabla',
      phone: 'blabla',
      photos: [
        'url',
        'url',
        'url',
      ],
      user: Uid3
    },
  },

  chats:{
    Uid3_Uid2: {...},
    Uid3_Uid4: {...},
    Uid3_UUid3_Uid1id4: {
      Mid1: {...},
      Mid2: {...},
      ...
    },
  }
}




