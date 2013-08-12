/*
 * precheck.h
 *
 *  Created on: 2013-8-12
 *      Author: leiming
 */

#ifndef PRECHECK_H_
#define PRECHECK_H_

enum token_id
{
	TOK_VAR=300,
	TOK_IF,
	TOK_ELSE,
	TOK_PROC,
	TOK_COMMENT,
	TOK_NUMBER,
	TOK_ENTER
};


#define LINE_LEN	512


#endif /* PRECHECK_H_ */
