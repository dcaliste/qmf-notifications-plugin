/*
 * Copyright (C) 2013-2014 Jolla Ltd.
 * Contact: Valerio Valerio <valerio.valerio@jollamobile.com>
 *
 * This file is part of qmf-notifications-plugin
 *
 * You may use this file under the terms of the BSD license as follows:
 *
 * "Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Nemo Mobile nor the names of its contributors
 *     may be used to endorse or promote products derived from this
 *     software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 */

#ifndef ACCOUNTSCACHE_H
#define ACCOUNTSCACHE_H

// accounts-qt
#include <Accounts/Manager>
#include <Accounts/Account>

// qmf
#include <ssoaccountmanager.h>

// Qt
#include <QObject>
#include <QUrl>
#include <QDebug>

struct AccountInfo
{
    QString name;
    QUrl providerIcon;
};

class AccountsCache : public QObject
{
    Q_OBJECT
public:
    explicit AccountsCache(QObject *parent = 0);

    AccountInfo accountInfo(const Accounts::AccountId accountId);

private slots:
    void accountCreated(Accounts::AccountId accountId);
    void accountRemoved(Accounts::AccountId accountId);
    void enabledEvent(Accounts::AccountId accountId);
    
private:
    void initCache();
    bool isEnabledMailAccount(const Accounts::AccountId accountId);
    SSOAccountManager _manager;
    QHash<Accounts::AccountId, Accounts::Account*> _accountsList;
};

#endif // ACCOUNTSCACHE_H
