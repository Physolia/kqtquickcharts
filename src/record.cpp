/*
 * Copyright 2014  Sebastian Gottfried <sebastiangottfried@web.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "record.h"

Record::Record(QObject* parent) :
    QObject(parent)
{
}

QVariantList Record::values() const
{
    return m_values;
}

void Record::setValues(const QVariantList& values)
{
    if (values != m_values)
    {
        m_values = values;
        emit valuesChanged(this);
    }
}

qreal Record::value(int column) const
{
    if (column >= m_values.count())
        return 0.0;
    return m_values.at(column).toReal();
}

void Record::setValue(int column, qreal value)
{
    while(column >= m_values.count()) {
        m_values.append(0.0);
    }
    m_values[column] = value;
    emit valuesChanged(this);
}
