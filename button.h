#ifndef __BUTTON_H__
#define __BUTTON_H__

enum btn_id {
	BTN_ID_NONE,
	BTN_ID_0,
	BTN_ID_1,
	BTN_ID_2,
	BTN_ID_NUM,
};

enum btn_event {
	BTN_EVT_DOWN,
	BTN_EVT_UP,
	BTN_EVT_CLICK,
	BTN_EVT_DOUBLE_CLICK,
	BTN_EVT_TRIPLE_CLICK,
	BTN_EVT_LONG_PRESS,
	BTN_EVT_LONG_LONG_PRESS,
	BTN_EVT_FIRST_DOWN,
	BTN_EVT_FIRST_UP,
	BTN_EVT_FIRST_CLICK,
	BTN_EVT_FIRST_LONG_PRESS,
	BTN_EVT_ULTRA_CLICK,
};

#define BTN_NAME_STR_SIZE 80

struct btn_dev {
	char name[BTN_NAME_STR_SIZE];
	enum btn_id id;
	enum btn_event evt;
	void *data;
	void (*handler)(enum btn_id id, enum btn_event evt, void *data);
};

int button_open(void);
int button_register(struct btn_dev *pdev);
int button_group_register(struct btn_dev *pdev, int nr);
int button_unregister(struct btn_dev *pdev);
int button_close(void);

#endif /* __BUTTON_H__ */
