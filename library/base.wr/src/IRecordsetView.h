/*
 * Copyright (c) 2010, 2018, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2.0,
 * as published by the Free Software Foundation.
 *
 * This program is also distributed with certain software (including
 * but not limited to OpenSSL) that is licensed under separate terms, as
 * designated in a particular file or component or in included license
 * documentation.  The authors of MySQL hereby grant you an additional
 * permission to link the program and your derivative works with the
 * separately licensed software that they have included with MySQL.
 * This program is distributed in the hope that it will be useful,  but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
 * the GNU General Public License, version 2.0, for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA 
 */

#pragma once

namespace MySQL {
  namespace Base {
  public
    interface class IRecordsetView {
      enum class ColumnHeaderIndicator { NoOrder = 0, OrderDesc = -1, OrderAsc = 1 };
      System::Windows::Forms::Control ^ control();

      delegate void ColumnResizeCallback(int column);
      delegate System::Windows::Forms::ContextMenuStrip ^ ColumnHeaderRightClickCallback(int column);

      void set_column_resize_callback(ColumnResizeCallback ^ callback);
      void set_column_header_right_click_callback(ColumnHeaderRightClickCallback ^ callback);

      int get_column_count();
      int get_column_width(int column);
      void set_column_width(int column, int width);
      int current_cell_row();
      int current_cell_column();
      void set_current_cell(int row, int column);
      void update_columns();

      void set_font(System::String ^ font, float size, System::Drawing::FontStyle style);
      void set_column_header_indicator(int column, ColumnHeaderIndicator order);
    };
  }
}
