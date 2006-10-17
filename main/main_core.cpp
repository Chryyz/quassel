/***************************************************************************
 *   Copyright (C) 2005/06 by The Quassel Team                             *
 *   devel@quassel-irc.org                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include <iostream>

#include <QCoreApplication>

#include "quassel.h"
#include "logger.h"
#include "proxy.h"

int main(int argc, char **argv) {

  Quassel::init();
  Logger *logger = new Logger();
  Quassel::setLogger(logger);

  QCoreApplication app(argc, argv);

  QCoreApplication::setOrganizationDomain("quassel-irc.org");
  QCoreApplication::setApplicationName("Quassel IRC");
  QCoreApplication::setOrganizationName("The Quassel Team");

  return app.exec();
}

QVariant proxyConnect(uint func, QVariant arg) {
  switch(func) {
    case LOAD_IDENTITIES: return (QVariant) CoreProxy::loadIdentities();
    case STORE_IDENTITIES: CoreProxy::storeIdentities(arg.toMap()); return 0;

  }
  return 0;
}
